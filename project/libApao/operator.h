#ifndef OPERATOR_H
#define OPERATOR_H
#include <string>
#include <vector>
#include <iostream>

#include "quantity.h"

using namespace std;

//define the Parameter List type
typedef vector<Quantity> ParameterList;

//define the Func type, which is a function pointer.
typedef Quantity(* Func)(ParameterList);


Quantity nullfunc(ParameterList paras);

Quantity if_then_else(ParameterList paras);

class Operator
{
    string name;
    Func func;
public:
    Operator();
    Operator(string opName, Func f);
    Quantity evaluate(ParameterList paras);
    bool isSameName(string &fn);

};

typedef Operator OP;

bool RegisterOp(string name, Func func);
OP* GetOperator(string name);

Var Eval(string name, ParameterList paras);

//arithm
Var PLUS(ParameterList paras);
Var MINUS(ParameterList paras);
Var TIMES(ParameterList paras);
Var DIVIDEDBY(ParameterList paras);
Var POWER(ParameterList paras);
Var LOG(ParameterList paras);
Var SIN(ParameterList paras);
Var SQRT(ParameterList paras);

Var MAX(ParameterList paras);
Var MIN(ParameterList paras);

//comp
Var EqualTo(ParameterList paras);
Var GreaterThan(ParameterList paras);
Var LessThan(ParameterList paras);
Var GreaterEqual(ParameterList paras);
Var LessEqual(ParameterList paras);

Var NOT(ParameterList paras);
Var AND(ParameterList paras);
Var OR(ParameterList paras);

//other
Var IDENTICAL(ParameterList paras);
Var E(ParameterList paras);//e
Var PI(ParameterList paras);//PI
Var I(ParameterList paras);//i

#endif // OPERATOR_H
