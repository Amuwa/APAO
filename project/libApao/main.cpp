#include <iostream>
#include "APAO.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Var a (3.141592657/2);

    ParameterList list;
    list.push_back(a);

    RegisterOp("sin", &SIN);
    Var b = Eval("sin", list);
    b.show();

    return 0;
}

