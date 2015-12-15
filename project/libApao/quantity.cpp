#include "quantity.h"

Quantity::Quantity(){
    type=Void;
    bValue = false;
    dValue = 0.0;
    imaginaryValue=0.0;
    errorMsg="";
}

Quantity::Quantity(bool bv)
{
    type = Bool;
    bValue = bv;
    dValue = 0.0;
    errorMsg="";
}

Quantity::Quantity(double dv)
{
    type = Number;
    dValue = dv;
    bValue = false;
    errorMsg="";
}

Quantity::Quantity(double dv, double iv){
    type = Complex;
    dValue =dv;
    imaginaryValue = iv;
    bValue =false;
    errorMsg="";
}

void Quantity::operator=(bool bv){
    type = Bool;
    bValue = bv;
    imaginaryValue=0;
    errorMsg="";
}
void Quantity::operator=(double dv){
    type = Number;
    dValue = dv;
    imaginaryValue=0;
    errorMsg="";
}
void Quantity::operator=(ComplexNumber cv){
    type = Complex;
    dValue = cv.realPart;
    imaginaryValue=cv.imaginaryPart;
    bValue =false;
    errorMsg="";
}

Quantity::Type Quantity::getType(){
    return type;
}
bool Quantity::getBoolValue(){
    return bValue;
}
double Quantity::getNumberValue(){
    return dValue;
}
ComplexNumber Quantity::getComplexValue(){
    ComplexNumber x;
    x.realPart = dValue;

    if(type == Number){imaginaryValue=0.0;}

    x.imaginaryPart = imaginaryValue;
    return x;
}

void Quantity::operator =(char* msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
    imaginaryValue = 0.0;
}
void Quantity::operator =(string msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
    imaginaryValue = 0.0;
}
Quantity::Quantity(string& msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
    imaginaryValue = 0.0;
}

string Quantity::getErrorMsg(){
    return errorMsg;
}

Quantity::Quantity(Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    imaginaryValue = v.imaginaryValue;
    errorMsg = v.errorMsg;
}
Quantity::Quantity(const Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    imaginaryValue = v.imaginaryValue;
    errorMsg = v.errorMsg;
}
void Quantity::operator =(Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    imaginaryValue = v.imaginaryValue;
    errorMsg = v.errorMsg;
}

void Quantity::operator =(Quantity v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    imaginaryValue = v.imaginaryValue;
    errorMsg = v.errorMsg;
}

void Quantity::show(){
    if(type == Bool){
        if(bValue){
            cout<<"TRUE"<<endl;
        }else{
            cout<<"FALSE"<<endl;
        }
    }else if(type == Number){
        cout<<dValue<<endl;
    }else if(type == Error){
        cout<<"ERROR: "<<errorMsg<<endl;
    }else if(type == Complex){
        cout<<dValue;
        if(imaginaryValue>=0){
            cout<<"+";
        }
        cout<<imaginaryValue<<"i"<<endl;
    }
    else {
        cout<<"NULL Quantity"<<endl;
    }

}

ostream& operator << (ostream& output,Var& c){
    if(c.getType() == Var::Bool){
        if(c.getBoolValue()){
            output<<"TRUE";
        }else{
            output<<"FALSE";
        }
    }else if(c.getType() == Var::Number){
        output<<c.getNumberValue();
    }else if(c.getType() == Var::Error){
        output<<"ERROR: "<<c.getErrorMsg();
    }else if(c.getType() == Var::Complex){
        ComplexNumber cn = c.getComplexValue();
        output<<cn.realPart<<"\t";
        if(cn.imaginaryPart>=0){
            output<<"+";
        }
        output<<cn.imaginaryPart<<"i";
    }
    else {
        output<<"NULL Quantity";
    }
    return output;
}
