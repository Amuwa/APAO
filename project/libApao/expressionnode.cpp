#include "expressionnode.h"

extern OP NullOP;

ExpressionNode::ExpressionNode()
{
    type = VARIABLE;
    theOp = &NullOP;
    parent = NULL;
    theVar = NULLVar;
}

ExpressionNode::ExpressionNode(string funcname){
    type = OPERATOR;
    theOp = GetOperator(funcname);
    theVar = NULLVar;
    parent=NULL;
    //cout<<funcname<<" node is created"<<endl;
}
ExpressionNode::ExpressionNode(double dv){
    type = VARIABLE;
    theOp = &NullOP;
    parent = NULL;
    theVar = dv;
}
ExpressionNode::ExpressionNode(double dv, double iv){
    type = VARIABLE;
    theOp = &NullOP;
    parent = NULL;

    ComplexNumber c;
    c.realPart=dv;
    c.imaginaryPart=iv;
    theVar = c;
}
ExpressionNode::ExpressionNode(bool bv){
    type = VARIABLE;
    theOp = &NullOP;
    parent = NULL;
    theVar = bv;
}


bool ExpressionNode::isRoot(){
    return (parent==NULL);
}

int ExpressionNode::level(){
    int rs =0;
    ExpressionNode *p = this;
    if(p->isRoot()){return rs;}
    while(!p->isRoot()){
        p = p->parent;
        rs++;
    }
    return rs;
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


ostream& operator << (ostream& output,ExpressionNode& c){
    int n = c.level();
    //output<<"{"<<endl;
    if(c.type==ExpressionNode::OPERATOR){
        for(int i=0;i<n;i++){
            output<<"    ";
        }
        output<<(*c.theOp);
        output<<":"<<endl;

        int k = c.children.size();

        for(int i=0;i<k;i++){
            output<<(*c.children[i]);
        }

        /*
        for(int i=0;i<n;i++){
            output<<"  ";
        }
        output<<"}"<<endl;
        */

    }else if(c.type == ExpressionNode::VARIABLE){
        for(int i=0;i<n;i++){
            output<<"    ";
        }
        output<<c.theVar;
        output<<endl;
    }
    //output<<"}"<<endl;
    return output;
}

