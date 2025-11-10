#include<stdio.h> 
int num1 = 10; // Program scope 
int num1 = 20; // NOT OK  
static int num2 = 20; // file scope 
namespace na 
{
    int num3 = 30;  // namespace scope 
    class Test
    {
        int num4 = 40; // class scope 
    }; 
}
int main()
{
    int num5 = 50; // function scope 
    {
        int num6 = 60; // Block scope 
    }
    return 0;
}
