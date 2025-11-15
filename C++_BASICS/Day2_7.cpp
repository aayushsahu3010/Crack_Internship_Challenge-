#include<stdio.h> 

namespace  na
{
    int num1 = 10;   
} 
namespace nb
{
    int num1 = 20; 
}

int main()
{
    int num1 = 30; 
    using namespace na; 
    printf("num1 : %d\n",num1); 

    using namespace nb;  
    printf("num1 : %d\n",nb::num1);
    return 0;
}
int main1()
{
    using namespace na; 
    printf("num1 : %d",num1); 
    return 0;
}
