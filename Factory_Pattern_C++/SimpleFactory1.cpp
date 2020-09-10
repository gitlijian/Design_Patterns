//
//  factory1.cpp
//  Factory_Pattern
//
//  Created by lijian on 2020/7/25.
//  Copyright © 2020 lijian. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 工厂模式
 */

// 抽象产品类
class Operation{
protected:
    double num1;
    double num2;
public:
    double get_n1(){
        return num1;
    }
    double get_n2(){
        return num2;
    }
    void set_n1(int num){
        num1 = num;
    }
    void set_n2(int num){
        num2 = num;
    }
    virtual double GetResult(){
        double result = 0;
        return result;
    }

};
//具体产品类
class OperationAdd:public Operation{
public:
    double GetResult(){
        double result = 0;
        result = num1 + num2;
        return result;
    }
};

//具体产品类
class OperationSub :public Operation{
public:
    double GetResult(){
        double result = 0;
        result = num1 - num2;
        return result;
    }
};

//具体产品类
class OperationMul :public Operation{
public:
    double GetResult(){
        double result = 0;
        result = num1 * num2;
        return result;
    }
};

//具体产品类
class OperationDiv :public Operation{
public:
    double GetResult(){
        double result = 0;
        if (num2!=0)
            result = num1 / num2;
        return result;
    }
};
//工厂类

class OperationFactory{
public:
    Operation* createOperation(char type){
        Operation* oper=NULL;
        switch (type)
            {
            case '+':
                oper = new OperationAdd;
                break;
            case '-':
                oper = new OperationSub;
                break;
            case '*':
                oper = new OperationMul;
                break;
            case '/':
                oper = new OperationDiv;
                break;
            }
        return oper;
    }
};

//int main(int argc, const char * argv[]) {
//
//    Operation* oper = NULL;
//    OperationFactory of;
//    oper = of.createOperation('/');
//    oper->set_n1(12);
//    oper->set_n2(3);
//    double res = oper->GetResult();
//    cout << res << endl;
//    if (oper != NULL)
//    {
//        delete oper;
//        oper = NULL;
//    }
//    return 0;
//}

// 缺点：需要添加新的运算时，需要修改工厂类

