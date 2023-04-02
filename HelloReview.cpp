// File HelloReview.cpp

#include <iostream>

using namespace std;

void hello_world();
void hello();
void world();

int main()
{
    hello_world();
    return 0;
}

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