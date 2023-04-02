// File Hello.cpp

#include <iostream>
#include "Hello.h"

using namespace std;

void hello()
{
    cout << "Hello ";
    return;
}

void world()
{
    cout << "world";
    return;
}

void hello_world()
{
    cout << endl << endl;
    hello();
    world();
    cout << endl << endl;
    return; 
}