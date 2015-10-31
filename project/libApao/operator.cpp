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
Quantity Operator::evaluate(ParameterList paras){
    return (*func)(paras);
}



/////////////////////



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

Var SIN(ParameterList paras){
    if(paras.size()<1){
        string msg = "SIN: no paras passed in.";
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
