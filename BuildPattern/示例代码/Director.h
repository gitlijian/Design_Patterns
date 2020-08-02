#ifndef DIRECTOR_H_INCLUDED
#define DIRECTOR_H_INCLUDED

#include "Builder.h"

//指挥者，指挥产品的创建流程
class Director{
public:

    //创建一台完整的电脑
    void ConstructComputer(Builder *builder){
        if(builder != NULL){

            builder->BuildMouse();
            cout<<"firstly,install mouse:....\n";

            builder->BuildKeyBoard();
             cout<<"then, install keyboard:....\n";

             cout<<"ok,construct computer successfully\n";
        }
    }


};


#endif // DIRECTOR_H_INCLUDED
