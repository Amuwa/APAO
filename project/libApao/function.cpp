#include "function.h"

Function::Function()
{
    Var msg = "NULL Function";
    rootNode = msg;
}

Var Function::evaluate(ParameterList paras){
    //copy paras
    paralist.clear();
    ParameterList::iterator it = paras.begin();
    for(;it!=paras.end();it++){
        Var v = (*it);
        paralist.push_back(v);
    }

    //evaluate

    return rootNode.evaluate();
}


void Function::operator=(string funcname){
    rootNode = funcname;
}
void Function::operator=(double dv){
    rootNode = dv;
}
void Function::operator=(bool bv){
    rootNode = bv;
}
void Function::operator=(ComplexNumber cv){
    rootNode = cv;
}
void Function::setAsIndexer(ParameterList* lst, int idx){
    rootNode.setAsIndexer(lst,idx);
}

ExpressionNode* Function::AddNewChild(string opfuncname)            //add a function/operator node (Not the "Function")
{
    return rootNode.AddNewChild(opfuncname);
}
ExpressionNode* Function::AddNewChild(double dv){                   //add a number variable node
    return rootNode.AddNewChild(dv);
}
ExpressionNode* Function::AddNewChild(double dv, double iv){         //add a complex number variable node: dv + iv * i;
    return rootNode.AddNewChild(dv,iv);
}
ExpressionNode* Function::AddNewChild(bool bv){                      //add a bool variable node
    return rootNode.AddNewChild(bv);
}
ExpressionNode* Function::AddNewChild(ParameterList* Lst, int idx){   //add a Indexer variable node
    return rootNode.AddNewChild(Lst,idx);
}

