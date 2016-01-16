#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include "quantity.h"
#include "operator.h"
#include <vector>

using namespace std;

class ExpressionNode
{
    OP* theOp;                          //if the node is an Operator
    Var theVar;                         //if the node is a Variable
    vector<ExpressionNode*> children;   //children nodes for the operator
    ExpressionNode* parent;             //parent node
public:
    enum Type{VARIABLE, OPERATOR} type;
    ExpressionNode();
    ExpressionNode(string funcname);
    ExpressionNode(double dv);
    ExpressionNode(double dv, double iv);
    ExpressionNode(bool bv);

    void operator=(string funcname);
    void operator=(double dv);
    void operator=(bool bv);
    void operator=(ComplexNumber cv);
    void setAsIndexer(ParameterList* lst, int idx);
    void operator=(Var v);

    Var evaluate();

    //
    bool isRoot();
    int level();
    OP* getOperator();
    Var getVariable();


    //
    void Clear();
    void AddChild(ExpressionNode* child);
    ExpressionNode* RemoveChild(ExpressionNode* child);

    ExpressionNode* AddNewChild(string opfuncname);             //add a function/operator node (Not the "Function")
    ExpressionNode* AddNewChild(double dv);                   //add a number variable node
    ExpressionNode* AddNewChild(double dv, double iv);         //add a complex number variable node: dv + iv * i;
    ExpressionNode* AddNewChild(bool bv);                      //add a bool variable node
    ExpressionNode* AddNewChild(ParameterList* Lst, int idx);   //add a Indexer variable node

    //
    void exchangePositions(int idx0,int idx1);          //exchange the positions of two children at idx0-th and idx1-th positions
    void insertChild(ExpressionNode* child, int idx0);  //insert child to the idx0-th position
    //

    friend ostream& operator << (ostream& output,ExpressionNode& c);

};

ostream& operator << (ostream& output,ExpressionNode& c);


#endif // EXPRESSIONNODE_H
