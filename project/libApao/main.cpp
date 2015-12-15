#include <iostream>
#include "APAO.h"

using namespace std;

int main()
{
    cout << "============================================\n\t\t Library APAO\n\t(c) 2015 MengChang WANG\n============================================\n" << endl;


    Var cc (2.718);
    Var dd (5.0);

    ParameterList list;

    list.push_back(cc);
    list.push_back(dd);

    RegisterOp("sin", &SIN);
    RegisterOp("IF-THEN-ELSE", &if_then_else);
    RegisterOp("plus", &PLUS);
    RegisterOp("minus", &MINUS);
    RegisterOp("div", &DIVIDEDBY);
    RegisterOp("pow", &POWER);
    RegisterOp("log", &LOG);

    RegisterOp(">", &GreaterThan);
    RegisterOp("==", &EqualTo);
    RegisterOp("<", &LessThan);
    RegisterOp(">=", &GreaterEqual);
    RegisterOp("<=", &LessEqual);
    RegisterOp("&&", &AND);
    RegisterOp("!", &NOT);
    RegisterOp("||", &OR);

    ExpressionNode root(string("IF-THEN-ELSE"));
    ExpressionNode Eq(string(">="));

    ExpressionNode div(string("div"));

    ExpressionNode add(string("plus"));
    add.AddNewChild(4.1);
    add.AddNewChild(3.0);

    div.AddChild(&add);
    div.AddNewChild(2.0);

    Eq.AddNewChild(3.5);
    Eq.AddChild(&div);

    root.AddChild(&Eq);
    root.AddNewChild(5.0);
    root.AddNewChild(20.0);

    cout<<root<<endl;

    Var x=root.evaluate();
    cout<<x<<endl;

    cout<<endl;

    return 0;
}

