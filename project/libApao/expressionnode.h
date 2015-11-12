#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include "quantity.h"
#include "operator.h"
#include <vector>

using namespace std;

class ExpressionNode
{
    OP* theOp;
    Var theVar;
    vector<ExpressionNode*> children;
    ExpressionNode* parent;
public:
    enum Type{VARIABLE, OPERATOR} type;
    ExpressionNode();
    Var evaluate();

    //
    void Clear();
    void AddChild(ExpressionNode* child);
    ExpressionNode* RemoveChild(ExpressionNode* child);

    ExpressionNode* AddNewChild(string funcname);
    ExpressionNode* AddNewChild(double dv);
    ExpressionNode* AddNewChild(double dv, double iv);// dv + iv * i;
    ExpressionNode* AddNewChild(bool bv);

};

#endif // EXPRESSIONNODE_H
