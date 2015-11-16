#include <iostream>
#include "APAO.h"

using namespace std;

int main()
{
    cout << "Hello APAO" << endl;


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

    //cout<<"\t"<<cc<<endl;
    //cout<<"/\t"<<dd<<endl;
    //cout<<"------------------------"<<endl;

    //Var rs=Eval("log",list);
    //cout<<"\t"<<rs<<endl;

    //string fn="log";
    ExpressionNode root(string("pow"));
    ExpressionNode div(string("div"));
    root.AddNewChild(2.710);
    div.AddNewChild(3.0);
    div.AddNewChild(2.0);
    root.AddChild(&div);

    cout<<root<<endl;

    Var x=root.evaluate();
    cout<<x<<endl;

    return 0;
}

