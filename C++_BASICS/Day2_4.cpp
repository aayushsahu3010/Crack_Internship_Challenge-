#include<stdio.h> 

namespace na // top-level namespace 
{ 
    int num1 = 10; 
    namespace nb // nested namespace 
    {
        int num2 = 20; 
    }
}
int main()
{
    printf("num1 : %d\n",na::num1); 
    printf("num1 : %d\n",na::nb::num2); 
    return 0;
}
