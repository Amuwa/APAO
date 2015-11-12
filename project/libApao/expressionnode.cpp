#include "expressionnode.h"

extern OP NullOP;

ExpressionNode::ExpressionNode()
{
    type = VARIABLE;
    theOp = &NullOP;
    parent = NULL;
}

Var ExpressionNode::evaluate(){
    if(type == VARIABLE){
        return theVar;
    }else {
        int C= children.size();
        ParameterList list;
        for(int i=0;i<C;i++){
            Var v = children.at(i)->evaluate();
            list.push_back(v);
        }
        return theOp->evaluate(list);
    }
}

void ExpressionNode::Clear(){
    children.clear();
}

void ExpressionNode::AddChild(ExpressionNode* child){
    children.push_back(child);
    child->parent = this;
}
ExpressionNode* ExpressionNode::RemoveChild(ExpressionNode* child){
    int C= children.size();
    int idx = -1;
    for(int i=0;i<C;i++){
        if(children.at(i) == child){
            idx = i;
            break;
        }
    }
    if(idx >= 0){
        children.erase(children.begin()+idx);
    }

    child->parent=NULL;

    return child;
}

ExpressionNode* ExpressionNode::AddNewChild(string funcname){
    ExpressionNode* xnode = new ExpressionNode();
    xnode->type = OPERATOR;
    xnode->theOp = GetOperator(funcname);

    children.push_back(xnode);
    xnode->parent = this;

    return xnode;
}

ExpressionNode* ExpressionNode::AddNewChild(double dv){
    ExpressionNode* xnode = new ExpressionNode();
    xnode->type = VARIABLE;
    xnode->theVar = dv;
    children.push_back(xnode);
    xnode->parent = this;
    return xnode;
}
ExpressionNode* ExpressionNode::AddNewChild(double dv,double iv){
    ExpressionNode* xnode = new ExpressionNode();
    xnode->type = VARIABLE;
    ComplexNumber cv;
    cv.realPart=dv;
    cv.imaginaryPart=iv;
    xnode->theVar = cv;
    children.push_back(xnode);
    xnode->parent = this;
    return xnode;
}
ExpressionNode* ExpressionNode::AddNewChild(bool bv){
    ExpressionNode* xnode = new ExpressionNode();
    xnode->type = VARIABLE;
    xnode->theVar = bv;
    children.push_back(xnode);
    xnode->parent = this;
    return xnode;
}
