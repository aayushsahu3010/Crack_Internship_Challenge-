#include<stdio.h> 
int num1 = 10; 
int main(int argc, char const *argv[])
{
    int num1 = 20; 
    printf("num1 : %d\n",num1 ); // 20 
    printf("num1 : %d\n",::num1 ); // 10 
    {
        int num1 = 30; 
        printf("num1 : %d\n",num1 ); // 30  
        printf("num1 : %d\n",::num1 ); //10 
    }
    return 0;
}