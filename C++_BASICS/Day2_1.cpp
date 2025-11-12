#include<stdio.h> 
namespace na
{
    int num1 = 10; // namespace scope 
}
int main(int argc, char const *argv[])
{
    printf("num1 : %d",na::num1); 
    return 0;
}
