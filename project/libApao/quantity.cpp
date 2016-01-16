#include "quantity.h"

Quantity::Quantity(){
    type=Void;
    bValue = false;
    dValue = 0.0;
    imaginaryValue=0.0;
    errorMsg="";
    theArray = NULL;
    theIdx = -1;
}

Quantity::Quantity(bool bv)
{
    type = Bool;
    bValue = bv;
    dValue = 0.0;
    errorMsg="";
    theArray = NULL;
    theIdx = -1;
}

Quantity::Quantity(double dv)
{
    type = Number;
    dValue = dv;
    bValue = false;
    errorMsg="";
    theArray = NULL;
    theIdx = -1;
}

Quantity::Quantity(double dv, double iv){
    type = Complex;
    dValue =dv;
    imaginaryValue = iv;
    bValue =false;
    errorMsg="";
    theArray = NULL;
    theIdx = -1;
}

Quantity::Quantity(vector<Quantity>* alist, int idx){
    type = Indexer;
    bValue = false;
    dValue = 0.0;
    imaginaryValue=0.0;
    errorMsg="";
    theArray = alist;
    theIdx = idx;
}

void Quantity::operator=(bool bv){
    type = Bool;
    bValue = bv;
    imaginaryValue=0;
    errorMsg="";

    theArray = NULL;
    theIdx = -1;
}
void Quantity::operator=(double dv){
    type = Number;
    dValue = dv;
    imaginaryValue=0;
    errorMsg="";

    theArray = NULL;
    theIdx = -1;
}
void Quantity::operator=(ComplexNumber cv){
    type = Complex;
    dValue = cv.realPart;
    imaginaryValue=cv.imaginaryPart;
    bValue =false;
    errorMsg="";

    theArray = NULL;
    theIdx = -1;
}

Quantity::Type Quantity::getType(){
    if(type == Indexer){
        if(theArray != NULL && theArray->size()>theIdx && theIdx >=0){
            return theArray->at(theIdx).getType();
        }
    }
    return type;
}
bool Quantity::getBoolValue(){
    if(type == Indexer){
        if(theArray != NULL && theArray->size()>theIdx && theIdx >=0){
            return theArray->at(theIdx).getBoolValue();
        }
    }
    return bValue;
}
double Quantity::getNumberValue(){
    if(type == Indexer){
        if(theArray != NULL && theArray->size()>theIdx && theIdx >=0){
            return theArray->at(theIdx).getNumberValue();
        }
    }
    return dValue;
}
ComplexNumber Quantity::getComplexValue(){
    if(type == Indexer){
        if(theArray != NULL && theArray->size()>theIdx && theIdx >=0){
            return theArray->at(theIdx).getComplexValue();
        }
    }
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

    theArray = NULL;
    theIdx = -1;
}
void Quantity::operator =(string msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
    imaginaryValue = 0.0;

    theArray = NULL;
    theIdx = -1;
}
Quantity::Quantity(string& msg){
    type=Error;
    errorMsg = msg;

    bValue = false;
    dValue = 0.0;
    imaginaryValue = 0.0;

    theArray = NULL;
    theIdx = -1;
}

string Quantity::getErrorMsg(){
    if(type == Indexer){
        if(theArray != NULL && theArray->size()>theIdx && theIdx >=0){
            return theArray->at(theIdx).getErrorMsg();
        }
    }
    return errorMsg;
}

Quantity::Quantity(Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    imaginaryValue = v.imaginaryValue;
    errorMsg = v.errorMsg;
    theArray = v.theArray;
    theIdx = v.theIdx;
}
Quantity::Quantity(const Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    imaginaryValue = v.imaginaryValue;
    errorMsg = v.errorMsg;
    theArray = v.theArray;
    theIdx = v.theIdx;
}
void Quantity::operator =(Quantity& v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    imaginaryValue = v.imaginaryValue;
    errorMsg = v.errorMsg;
    theArray = v.theArray;
    theIdx = v.theIdx;
}

void Quantity::operator =(Quantity v){
    type = v.type;
    bValue = v.bValue;
    dValue = v.dValue;
    imaginaryValue = v.imaginaryValue;
    errorMsg = v.errorMsg;
    theArray = v.theArray;
    theIdx = v.theIdx;
}

void Quantity::setAsIndexer (vector<Quantity>* alist, int idx){
    type == Indexer;
    bValue = false;
    dValue = 0.0;
    imaginaryValue=0.0;
    errorMsg="";
    theArray = alist;
    theIdx = idx;
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
    }else if(type == Indexer){
        cout<<"An Indexer: ";
        if(theArray!=NULL && theArray->size()>theIdx && theIdx>=0){
            cout<<theArray->at(theIdx);
        }else{
            cout<<"Unknown value";
        }
        cout<<endl;
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
    }else if(c.getType() == Var::Indexer){
        //output<<"An Indexer: ";
        if(c.theArray!=NULL && c.theArray->size()>c.theIdx && c.theIdx>=0){
            output<<c.theArray->at(c.theIdx);
            output<<" [Indexer]";
        }else{
            output<<"[Indexer]Unknown value";
        }
        //output<<endl;
    }
    else {
        output<<"NULL Quantity";
    }
    return output;
}
