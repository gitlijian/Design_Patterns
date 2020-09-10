#include<iostream>
using namespace std;

#define MAXSIZE 100

#include "AbFac.h"
#include "Mouse.h"
#include "KeyBoard.h"

int main()
{
    AbFactory * abFac = new DellFactory();

    AbMouse * mouse = abFac->CreateMouse();
    AbKeyBoard * keyboard = abFac->CreateKeyBoard();

    mouse->SayHi();
    keyboard->SayHi();

    delete abFac;
    delete mouse;
    delete keyboard;

    return 0;
}
