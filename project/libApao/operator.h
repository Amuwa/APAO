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
Var Eval(string name, ParameterList paras);

Var SIN(ParameterList paras);

Var IDENTICAL(ParameterList paras);


#endif // OPERATOR_H
