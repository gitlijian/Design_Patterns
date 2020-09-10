#include<iostream>
using namespace std;

#define MAXSIZE 100

#include "AbFac.h"
#include "Mouse.h"
#include "KeyBoard.h"
#include "HpBuilder.h"
#include "Director.h"
#include "DellBuilder.h"

int main()
{
   Builder * builder = new DellBuilder();

   Director *dir = new Director();

   dir->ConstructComputer(builder);

   return 0;
}
