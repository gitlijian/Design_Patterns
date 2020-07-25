//
//  AbstractFactory.cpp
//  Factory_Pattern
//
//  Created by lijian on 2020/7/25.
//  Copyright © 2020 lijian. All rights reserved.
//

/*
 指定义一个创建一系列相关或相互依赖的对象接口，而不需要指定他们具体的类
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
        cout << " SingleCoreA"<<endl;
    }
};

class SingleCoreB:public SingleCore
{
public:
    void Show()
    {
        cout << " SingleCoreB"<<endl;
    }
};

class MultiCore
{
public:
    virtual void Show() = 0;
};

class MultiCoreA:public MultiCore
{
public:
    void Show()
    {
        cout << " MultiCoreA" << endl;
    }
};

class MultiCoreB:public MultiCore
{
public:
    void Show()
    {
        cout << " MultiCoreB" << endl;
    }
};

class CoreFactory
{
public:
    virtual SingleCore* createSingleCore() = 0;
    virtual MultiCore* createMultiCore() = 0;
};

class CoreFactoryA:public CoreFactory
{
public:
    SingleCore* createSingleCore()
    {
        cout << "create SingleCoreA" << endl;
        return new SingleCoreA();
    }
    MultiCore* createMultiCore()
    {
        cout << "create MultiCoreA" << endl;
        return new MultiCoreA();

    }
};

class CoreFactoryB:public CoreFactory
{
public:
    SingleCore* createSingleCore()
    {
        cout << "create SingleCoreB" << endl;
        return new SingleCoreB();
    }
    MultiCore* createMultiCore()
    {
        cout << "create MultiCoreB" << endl;
        return new MultiCoreB();
    }
};

int main()
{
    CoreFactoryB Fcb;
    SingleCore* core = Fcb.createSingleCore();
    MultiCore* Mcore = Fcb.createMultiCore();
    core->Show();
    Mcore->Show();
    CoreFactoryA Fca;
    core = Fca.createSingleCore();
    Mcore = Fca.createMultiCore();
    core->Show();
    Mcore->Show();
}

/*
 从简单工厂、工厂方法、抽象工厂。它们的抽象程度依次增高
 也越来越符合开放封闭原则，解耦程度逐渐增高
 */
