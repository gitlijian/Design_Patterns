//
//  FacotryMethod.cpp
//  Factory_Pattern
//
//  Created by lijian on 2020/7/25.
//  Copyright © 2020 lijian. All rights reserved.
//

/*
 定义一个创建对象的接口，让子类来决定创建哪一个类的实例，将创建过程延迟到子类
 
 　例如：
 生产处理器的厂家，决定再开设一个工厂专门用来生产B型号的单核
 一个工厂用来生产A型号的单核。这时客户要A型号的核，就找A工厂要；B型号的，找B工厂要;
 */
#include <iostream>
using namespace std;
class SingleCore
{
public:
    virtual void Show() = 0;
};
class SingleCoreA:public SingleCore
{
public:
    void Show()
    {
        cout << "Single Core A" << endl;
    }
};
class SingleCoreB:public SingleCore
{
public:
    void Show()
    {
        cout << "Single Core B" << endl;
    }
};
class Factory
{
public:
    virtual SingleCore* CreateSingleCore() = 0;
};
class FactoryA:public Factory
{
public:
    SingleCore* CreateSingleCore()
    {
        cout << "Create SingleCore A" << endl;
        return new SingleCoreA();
    }
};
class FactoryB:public Factory
{
public:
    SingleCore* CreateSingleCore()
    {
        cout << "Create SingleCore B" << endl;
        return new SingleCoreB();
    }
};
//int main()
//{
//    FactoryA m;
//    SingleCore* p = m.CreateSingleCore();
//    p->Show();
//    FactoryB n;
//    p = n.CreateSingleCore();
//    p->Show();
//}

/*
 缺点：每增加一个新的产品就需要创建一个该产品的工厂类
 */
