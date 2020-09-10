#ifndef DELLBUILDER_H_INCLUDED
#define DELLBUILDER_H_INCLUDED

#include "AbFac.h"
#include "Builder.h"

class DellBuilder: public Builder{
public:

    DellBuilder(){
        comFac = new DellFactory();

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


#endif // DELLBUILDER_H_INCLUDED
