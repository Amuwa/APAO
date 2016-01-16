#ifndef QUANTITY_H
#define QUANTITY_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct ComplexNumber{
    double realPart;
    double imaginaryPart;
};

class Quantity
{
    double dValue;
    double imaginaryValue;

    bool bValue;
    string errorMsg;

    //for indexer
    vector<Quantity>* theArray;
    int theIdx;

public:
    enum Type {Bool, Number, Complex,Void, Indexer, Error} type;
    Quantity(bool bv);
    Quantity(double dv);
    Quantity(double dv, double iv);
    Quantity(vector<Quantity>* alist, int idx);
    Quantity();
    void operator=(bool bv);
    void operator=(double dv);
    void operator=(ComplexNumber cv);

    Type getType();
    bool getBoolValue();
    double getNumberValue();
    ComplexNumber getComplexValue();

    string getErrorMsg();
    void operator =(char* msg);
    void operator =(string msg);
    Quantity(string& msg);
    //Quantity(char* msg);

    Quantity(Quantity& v);
    Quantity(const Quantity& v);

    void operator =(Quantity& v);
    void operator =(Quantity v);

    void setAsIndexer (vector<Quantity>* alist, int idx);

    void show();
    friend ostream& operator << (ostream& output,Quantity& c);

};

const Quantity nullQuantity;

#ifndef NULLVar
#define NULLVar nullQuantity
#endif

typedef Quantity Var;


ostream& operator << (ostream& output,Var& c);


#endif // QUANTITY_H
