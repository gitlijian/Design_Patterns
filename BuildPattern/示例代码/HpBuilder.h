#ifndef HPBUILDER_H_INCLUDED
#define HPBUILDER_H_INCLUDED

#include "Builder.h"
#include "Mouse.h"
#include "KeyBoard.h"

class HpBuilder: public Builder{
public:

    HpBuilder(){
        comFac = new HpFactory();       //创建hp工厂
    }

    void BuildMouse() override{
        mouse = comFac->CreateMouse();
    }

    void BuildKeyBoard()override{
        keyBoadrd = comFac->CreateKeyBoard();
    }



private:
    AbFactory *comFac;
    AbMouse *mouse;
    AbKeyBoard * keyBoadrd;


};


#endif // HPBUILDER_H_INCLUDED
