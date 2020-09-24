#ifndef FACADE_H_INCLUDED
#define FACADE_H_INCLUDED

#include "SubSystem.h"

class Facade{
public:
    SubSystemOne one;
    SubSystemTwo two;
    SubSystemThree three;

    void MethodA(){
        one.MethodOne();
        two.MethodTwo();
    }

    void MethodB(){

        one.MethodOne();
        three.MethodThree();
    }


};


#endif // FACADE_H_INCLUDED
