#include<stdio.h> 

namespace na 
{
    int num1 = 10; 
}
int main(int argc, char const *argv[])
{
    int num1 = 20; 
    using namespace na;
    printf("num1 : %d",num1);  
    return 0;
}

int main2(int argc, char const *argv[])
{
    using namespace na; 
    printf("num1 : %d",num1); 
    return 0;
}

int main1(int argc, char const *argv[])
{
    printf("num1 : %d",na::num1); 
    return 0;
}
