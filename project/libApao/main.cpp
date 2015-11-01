#include <iostream>
#include "APAO.h"

using namespace std;

int main()
{
    cout << "Hello APAO" << endl;


    Var cc (3.1, -2.0);
    Var dd (true);

    ParameterList list;

    list.push_back(cc);
    list.push_back(dd);

    RegisterOp("sin", &SIN);
    RegisterOp("IF-THEN-ELSE", &if_then_else);
    RegisterOp("plus", &PLUS);
    RegisterOp("minus", &MINUS);

    cout<<"\t"<<cc<<endl;
    cout<<"+\t"<<dd<<endl;
    cout<<"------------------------"<<endl;

    Var rs=Eval("plus",list);
    cout<<"\t"<<rs<<endl;

    return 0;
}

