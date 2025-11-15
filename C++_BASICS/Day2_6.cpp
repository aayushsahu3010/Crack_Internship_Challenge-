#include<stdio.h> 

namespace na
{
    int num1 = 10; 
}
int num1 = 10; 
int main(int argc, char const *argv[])
{
     
    using namespace na; 
    printf("num1 : %d",::num1); 
    return 0;
} 
