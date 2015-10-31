#include "quantity.h"

Quantity::Quantity(){
    type=Void;
    bValue = false;
    dValue = 0.0;
}

Quantity::Quantity(bool bv)
{
    type = Bool;
    bValue = bv;
    dValue = 0.0;
}

Quantity::Quantity(double dv)
{
    type = Number;
    dValue = dv;
    bValue = false;
}

void Quantity::operator=(bool bv){
    type = Bool;
    bValue = bv;
}
void Quantity::operator=(double dv){
    type = Number;
    dValue = dv;
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

void Quantity::operator =(char* msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
}
void Quantity::operator =(string msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
}
Quantity::Quantity(string& msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
}
/*
Quantity::Quantity(char* msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
}
*/
string Quantity::getErrorMsg(){
    return errorMsg;
}

Quantity::Quantity(Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    errorMsg = v.errorMsg;
}
Quantity::Quantity(const Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    errorMsg = v.errorMsg;
}
void Quantity::operator =(Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    errorMsg = v.errorMsg;
}
void Quantity::operator =(Quantity v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
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
    }else {
        cout<<"NULL Quantity"<<endl;
    }

}
