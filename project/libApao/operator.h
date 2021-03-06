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
typedef Quantity(* OpFunc)(ParameterList);


Quantity nulloperator(ParameterList paras);

Quantity if_then_else(ParameterList paras);

class Operator
{
    string name;
    OpFunc func;
public:
    Operator();
    Operator(string opName, OpFunc f);
    Quantity evaluate(ParameterList paras);
    bool isSameName(string &fn);
    string getName();
    friend ostream& operator << (ostream& output,Operator& o);
};

ostream& operator << (ostream& output,Operator& o);

typedef Operator OP;

bool RegisterOp(string name, OpFunc func);
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
Var Norm(ParameterList paras);//Norm/Abstrct

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

//


#endif // OPERATOR_H
