#ifndef MOUSE_H_INCLUDED
#define MOUSE_H_INCLUDED


#include<iostream>
using namespace std;

#define MAXSIZE 100


class AbMouse{

public:
    AbMouse(){}

    virtual void SayHi() = 0;

};

class DellMouse: public AbMouse{

public:
    DellMouse(){}

    void SayHi()override{
        cout<<"I am DellMouse\n";
    }
};


class HpMouse: public AbMouse{
public:
    HpMouse(){}

    void SayHi()override{
        cout<<"I am HpMouse\n";
    }

};




#endif // MOUSE_H_INCLUDED
