#ifndef QUANTITY_H
#define QUANTITY_H
#include <string>
#include <iostream>

using namespace std;

class Quantity
{
    double dValue;
    bool bValue;
    string errorMsg;
public:
    enum Type {Bool, Number, Void, Error} type;
    Quantity(bool bv);
    Quantity(double dv);
    Quantity();
    void operator=(bool bv);
    void operator=(double dv);

    Type getType();
    bool getBoolValue();
    double getNumberValue();
    string getErrorMsg();
    void operator =(char* msg);
    void operator =(string msg);
    Quantity(string& msg);
    //Quantity(char* msg);

    Quantity(Quantity& v);
    Quantity(const Quantity& v);

    void operator =(Quantity& v);
    void operator =(Quantity v);

    void show();

};

const Quantity nullQuantity;

typedef Quantity Var;

#endif // QUANTITY_H
