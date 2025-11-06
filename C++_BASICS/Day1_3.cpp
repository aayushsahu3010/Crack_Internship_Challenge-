
#include<stdio.h> 

//call by address / pass by address 
void swap(int *a , int *b) // function parameter / argument 
{
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}
int main()
{
    int a = 10; 
    int b = 20;
    swap(&a,&b); 
    printf("a : %d\n",a); 
    printf("b : %d\n",b);  
    return 0;
}
