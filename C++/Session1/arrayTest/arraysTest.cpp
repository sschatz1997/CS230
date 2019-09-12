//arrayTest.cpp
#include<iostream>

using namespace std;

void modifyA(int* bPTR)
{
     *bPTR = 99;
 }

int main()
{
    int a= 9;
    
    cout <<"a = "<<a<<endl;
    cout <<"a is located here :"<<&a<<endl;
    
    int* aPTR;
    
    aPTR = &a;
    
    *aPTR = -3;
    
    cout <<"a = "<<a<<endl;
    
    modifyA(&a);
    
    cout <<"a = "<<a<<endl;
    return 0;
}
