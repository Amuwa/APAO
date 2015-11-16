#include "operator.h"

Quantity nullfunc(ParameterList paras){
    paras.size();//to avoid warning
    return nullQuantity;
}

Quantity if_then_else(ParameterList paras){
    string errmsg = "IF-ELSE-THEN Error";
    if(paras.size() <2){
        Quantity rs(errmsg);
        return rs;
    }else if(paras.size() == 2){
        Quantity cond = paras.at(0);
        Quantity body = paras.at(1);
        if(cond.getType() != Quantity::Bool){
            Quantity rs=errmsg;
            return rs;
        }else{
            if(cond.getBoolValue()){
                return body;
            }else{
                return nullQuantity;
            }
        }
    }else if(paras.size() == 3){
        Quantity cond = paras.at(0);
        Quantity body = paras.at(1);
        Quantity body2 = paras.at(2);
        if(cond.getType() != Quantity::Bool){
            Quantity rs=errmsg;
            return rs;
        }else{
            if(cond.getBoolValue()){
                return body;
            }else{
                return body2;
            }
        }
    }else{
        string errmsg = "IF-ELSE-THEN Error: more than 3 parameters.";
        Quantity rs(errmsg);
        return rs;
    }
}


Operator::Operator()
{
    name = "NULL";
    func = &nullfunc;
}

Operator::Operator(string opName, Func f){
    name = opName;
    func = f;
}

bool Operator::isSameName(string& fn){
    return (name == fn);
}
string Operator::getName(){
    return name;
}

Quantity Operator::evaluate(ParameterList paras){
    return (*func)(paras);
}

ostream& operator << (ostream& output,Operator& o){
    output<<o.name;
    return output;
}

/////////////////////

OP NullOP("NULLFUNC",&nullfunc); //Null Func


vector<Operator*> AvailableOperators;

bool RegisterOp(string name, Func func){
    int C= AvailableOperators.size();
    for(int i=0;i<C;i++){
        if(AvailableOperators.at(i)->isSameName(name)){
            cout<<"Op: "<<name<<" already exist."<<endl;
            return false;
        }
    }
    Operator * op = new Operator(name,func);
    AvailableOperators.push_back(op);
    return true;
}

OP* GetOperator(string name){
    OP* op = &NullOP;
    int C= AvailableOperators.size();
    for(int i=0;i<C;i++){
        if(AvailableOperators.at(i)->isSameName(name)){
            op = AvailableOperators.at(i);
            return op;
        }
    }
    cout<<"OPERATOR ["<<name<<"] not registered."<<endl;
    return op;
}

Var Eval(string name, ParameterList paras){
    int C= AvailableOperators.size();
    for(int i=0;i<C;i++){
        if(AvailableOperators.at(i)->isSameName(name)){
            return AvailableOperators.at(i)->evaluate(paras);
        }
    }
    return nullQuantity;
}

#include <math.h>
#include <stdlib.h>

//
Var PLUS(ParameterList paras){
    int C = paras.size();
    if(C<1){
        string msg = "No value passed in (PLUS).";
        Var err=msg;
        return err;
    }
    double realpart =0.0;
    double imgnpart = 0.0;
    for(int i=0;i<C;i++){
        if(paras.at(i).type == Var::Number || paras.at(i).type == Var::Complex){
            realpart += paras.at(i).getComplexValue().realPart;
            imgnpart += paras.at(i).getComplexValue().imaginaryPart;
        }else{
            string msg = "Non- Number/Complex value passed in (PLUS).";
            Var err=msg;
            return err;
        }
    }
    if(imgnpart == 0){
        Var rs = realpart;
        return rs;
    }else{
        Var rs(realpart,imgnpart);
        return rs;
    }
}

Var MINUS(ParameterList paras){
    int C = paras.size();
    if(C<1){
        string msg = "No value passed in (MINUS).";
        Var err=msg;
        return err;
    }else if(C>2){
        string msg = "More than two values passed in (MINUS).";
        Var err=msg;
        return err;
    }
    else if(C==1){
        if(paras.at(0).type == Var::Number){
            Var rs = -(paras.at(0).getNumberValue());
            return rs;
        }
    }else{

        if(paras.at(0).type == Var::Number || paras.at(0).type == Var::Complex){
            if(paras.at(1).type == Var::Number || paras.at(1).type == Var::Complex){
                double r = paras.at(0).getComplexValue().realPart - paras.at(1).getComplexValue().realPart;
                double i = paras.at(0).getComplexValue().imaginaryPart - paras.at(1).getComplexValue().imaginaryPart;
                if(i==0){
                    Var rs = r;
                    return rs;
                }else{
                    Var rs(r,i);
                    return rs;
                }
            }
        }

        string msg = "Non- Number/Complex values passed in (MINUS).";
        Var err=msg;
        return err;
    }
}


Var TIMES(ParameterList paras){
    int C = paras.size();
    if(C<1){
        string msg = "No values passed in (Times).";
        Var err=msg;
        return err;
    }else if(C==1){
        if(paras.at(0).type == Var::Number ||paras.at(0).type == Var::Complex){
            return paras.at(0);
        }else{
            string msg = "Non Number/Complex values passed in (Times).";
            Var err=msg;
            return err;
        }
    }else{
        //times
        if(paras.at(0).type == Var::Number ||paras.at(0).type == Var::Complex){
            if(paras.at(1).type == Var::Number ||paras.at(1).type == Var::Complex){
                ComplexNumber c0=paras.at(0).getComplexValue();
                ComplexNumber c1=paras.at(1).getComplexValue();
                double realpart = c0.realPart*c1.realPart - c0.imaginaryPart*c1.imaginaryPart;
                double imgpart = c0.realPart*c1.imaginaryPart + c1.realPart*c0.imaginaryPart;
                Var rs(realpart,imgpart);
                return rs;
            }else{
                string msg = "Non Number/Complex values passed in (Times).";
                Var err=msg;
                return err;
            }
        }else{
            string msg = "Non Number/Complex values passed in (Times).";
            Var err=msg;
            return err;
        }
    }
}

Var DIVIDEDBY(ParameterList paras){
    int C = paras.size();
    if(C<2){
        string msg = "Less than 2 values passed in (DividedBy).";
        Var err=msg;
        return err;
    }else{ // (C>=2) //>2 to allow more variables, but only the first two are involved, the rest vars can be move to other nodes in future operations
        if(paras.at(0).type == Var::Number || paras.at(0).type == Var::Complex){
            ComplexNumber cv =paras.at(0).getComplexValue();
            if(paras.at(1).type == Var::Number || paras.at(1).type == Var::Complex){
                ComplexNumber cvd = paras.at(1).getComplexValue();
                if(cvd.realPart == 0.0 && cvd.imaginaryPart == 0.0){
                    string msg = "Divided by Zero";
                    Var err=msg;
                    return err;
                }else{

                    if(paras.at(0).type == Var::Number && paras.at(1).type == Var::Number){
                        Var rs = (paras.at(0).getNumberValue()/paras.at(1).getNumberValue());
                        return rs;
                    }else{
                       //complex division!!!
                        ComplexNumber cj_cvd=cvd;
                        cj_cvd.realPart = cvd.realPart;
                        cj_cvd.imaginaryPart = - cvd.imaginaryPart;
                        double R = cvd.realPart*cvd.realPart + cvd.imaginaryPart*cvd.imaginaryPart;
                        ComplexNumber over ;
                        over.realPart = (cv.realPart*cj_cvd.realPart - cv.imaginaryPart*cj_cvd.imaginaryPart)/R;
                        over.imaginaryPart = (cv.realPart*cj_cvd.imaginaryPart + cv.imaginaryPart*cj_cvd.realPart)/R;
                        Var rs (over.realPart,over.imaginaryPart);
                        return rs;
                    }
                }
            }
        }
    }
    string msg = "Wrong values passed in (DividedBy).";
    Var err=msg;
    return err;
}

Var POWER(ParameterList paras){
    //x^y
    int C = paras.size();
    if(C<2){
        string msg = "Less than 2 values passed in (Power).";
        Var err=msg;
        return err;
    }else{
        if(paras.at(0).type == Var::Number ){
            if(paras.at(1).type == Var::Number){
                double base = paras.at(0).getNumberValue();
                double order = paras.at(1).getNumberValue();
                Var rs = pow(base,order);
                return rs;
            }
        }
        string msg = "Non-number values passed in (Power).";
        Var err=msg;
        return err;
    }
}

Var LOG(ParameterList paras){
    //log(x)
    int C = paras.size();
    if(C<1){
        string msg = "No values passed in (Log).";
        Var err=msg;
        return err;
    }else{
        if(paras.at(0).type == Var::Number ){

                double x = paras.at(0).getNumberValue();
                Var rs = log(x);
                return rs;
        }
        string msg = "Non-number values passed in (Log).";
        Var err=msg;
        return err;
    }
}

Var SQRT(ParameterList paras){
    //sqrt (x)
}

Var SIN(ParameterList paras){
    if(paras.size()<1){
        string msg = "SIN: no para passed in.";
        Var rs = msg;
        return rs;
    }
    if(paras.at(0).getType() != Var::Number){
        string msg = "SIN: a non-number parameter is passed in.";
        Var rs = msg;
        return rs;
    }
    return sin(paras.at(0).getNumberValue());
}

Var IDENTICAL(ParameterList paras){
    if(paras.size()<1){
        string msg = "IDENTICAL: no paras passed in.";
        Var rs = msg;
        return rs;
    }
    return paras.at(0);
}
