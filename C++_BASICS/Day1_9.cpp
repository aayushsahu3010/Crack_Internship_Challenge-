#include<stdio.h> 

int main(int argc, char const *argv[])
{
    int num1 = 10; 
    const int *ptr = &num1; 
    num1 = 20; // OK 
    //*ptr = 30; // NOT OK  
    return 0;
}

int main6(int argc, char const *argv[])
{
    const int num1 = 10;
    const int *ptr = &num1; ;  
    return 0;
}

int main5()
{
    const int num1 = 10;     
    const int * const ptr = &num1; 
    //ptr is a constant pointer storing address of constant integer variable 
    printf("num1 : %d\n",num1); 
    printf("*ptr : %d\n",*ptr);
    //num1 = 20; // NOT OK 
    //*ptr = 20; // NOT OK 
    //const int num2 = 20; 
    //ptr = &num2; // NOT OK  
    return 0;
}

int main4(int argc, char const *argv[])
{
    int num1 = 10;
    int num2 = 20; 
    int * const ptr = &num1; 
    //ptr is a constant pointer storing the address of non-constant int variable 
    //ptr = &num2; // NOT OK 
    printf("num1 : %d\n",num1); // 10  
    printf("*ptr : %d\n",*ptr); // 10 
    num1 = 20;   
    printf("num1 : %d\n",num1); // 20 
    printf("*ptr : %d\n",*ptr); // 20  
    //ptr = &num2;   // NOT OK 
    return 0;
}

int main3()
{
    const int num1 = 10;
    const int num2 = 10;
    const int *ptr = &num1; 
    //int const *ptr = &num1; 
    printf("num1 : %d",num1); //10 
    printf("*ptr : %d",*ptr); //10 
    //*ptr = 20; // NOT OK   
    //num1 = 30; // NOT OK 
    ptr = &num2; // OK 
    return 0;
}

int main2(int argc, char const *argv[])
{
    int num = 10; 
    int *ptr = &num; 
    num = 20; // OK 
    printf("num : %d\n",num); // 20 
    *ptr = 30;  
    printf("num : %d\n",num); // 30
    printf("*ptr : %d\n",*ptr); // 30
    return 0;
}

int main1()
{
    const int num1 = 10; 
    printf("num1 : %d",num1); // OK 
    //num1 = 20; // NOT OK 
    return 0;
}
