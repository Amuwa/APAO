#ifndef FUNCTION_H
#define FUNCTION_H

#include "APAO.h"

#include <vector>

/*
 * Function two parts:
 *      (1) Parameters, whose value can be set
 *      (2) Logic, the operations/expressions on the Parameters
 *
 *
*/

using namespace std;

class Function
{
    ParameterList paralist;

    Var getPara(int idx);              //get the idx-th para
    ExpressionNode rootNode;          //the root node of the logic

public:
    Function();
    Var evaluate(ParameterList paras); //the returned value for the input paras

    //to buildup the rootNode using Indexer vars ????

    void operator=(string funcname);
    void operator=(double dv);
    void operator=(bool bv);
    void operator=(ComplexNumber cv);
    void setAsIndexer(ParameterList* lst, int idx);

    ExpressionNode* AddNewChild(string opfuncname);             //add a function/operator node (Not the "Function")
    ExpressionNode* AddNewChild(double dv);                   //add a number variable node
    ExpressionNode* AddNewChild(double dv, double iv);         //add a complex number variable node: dv + iv * i;
    ExpressionNode* AddNewChild(bool bv);                      //add a bool variable node
    ExpressionNode* AddNewChild(ParameterList* Lst, int idx);   //add a Indexer variable node

};

#endif // FUNCTION_H
