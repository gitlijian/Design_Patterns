#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED


#include<iostream>
using namespace std;

#define MAXSIZE 100

class AbKeyBoard{

public:

    virtual void SayHi() = 0;       //定义纯虚函数
};

class DellKeyBoard:public AbKeyBoard{

public:
    void SayHi()override{
         cout<<"I am DellKeyBoard\n";
    }
};

class HpKeyBoard:public AbKeyBoard{

public:
    void SayHi()override{
         cout<<"I am HpKeyBoard\n";
    }
};

#endif // KEYBOARD_H_INCLUDED
