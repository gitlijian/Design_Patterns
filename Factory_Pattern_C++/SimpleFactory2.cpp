//
//  main.cpp
//  Factory_Pattern
//
//  Created by lijian on 2020/7/25.
//  Copyright © 2020 lijian. All rights reserved.
//

/*
 简单工厂模式
 由工厂决定创建出哪一类产品的实例
 
 例如：

 　　　　有一家生产处理核的厂家，它只有一个工厂，能够生产两种型号的处理器核。客户需要什么样的处理器，一定要显示地告诉生产工厂。
 */

#include <iostream>
using namespace std;

enum CTYPE {COREA,COREB};
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
    SingleCore* CreateSingleCore(enum CTYPE c)
    {
        if(c == COREA)
        {
            cout << "Create Single Core A" << endl;
            return new SingleCoreA;
        }
        else if(c == COREB)
        {
            cout << "Create Single Core B" << endl;
            return new SingleCoreB;
        }
        else
        {
            cout << "Don't have this Core" << endl;
            return NULL;
        }
    }
};

//int main()
//{
//        Factory m;
//        SingleCore* p = m.CreateSingleCore(COREA);
//        p->Show();
//        p = m.CreateSingleCore(COREB);
//        p->Show();
//}

// 缺点：当需要增加新的核时，会修改工厂类，违反了开放封闭原则：可扩展但不可修改
