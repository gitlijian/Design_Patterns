#ifndef ABFAC_H_INCLUDED
#define ABFAC_H_INCLUDED


#include<iostream>

#include "Mouse.h"
#include "KeyBoard.h"

using namespace std;



class AbFactory{
public:

    virtual AbMouse* CreateMouse() = 0;
    virtual AbKeyBoard* CreateKeyBoard() = 0;

};

//Hp 工厂
class HpFactory:public AbFactory
{
public:

    HpMouse* CreateMouse() override{

         cout<<"Produce HpMouse...\n";
        return new HpMouse();
    }

    HpKeyBoard* CreateKeyBoard()override{
        cout<<"Produce HpKeyBoard...\n";
        return new HpKeyBoard();
    }

};

//Dell工厂
class DellFactory: public AbFactory{
public:
     DellMouse* CreateMouse() override{
         cout<<"Produce DellMouse...\n";
        return new DellMouse();
    }

    DellKeyBoard* CreateKeyBoard()override{
        cout<<"Produce DellKeyBoard...\n";
        return new DellKeyBoard;
    }

};

#endif // ABFAC_H_INCLUDED
