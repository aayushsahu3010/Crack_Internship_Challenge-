#include<stdio.h> 

//main is a user-defined function 
//Execution of program begins from main 
//per-project we can write only one main function 
//main is called a entry-point function 
//if we dont write main it will give linker error 
//we cannot make main static , const 
//main function must be global we cannot write main function inside structure /function / class 
//purpose of main function is to call other functions 
//OS calls the main function 
void print(void); //global declaration 
int main()
{
    //void print(void); //local declaration 
    print( ); 
    return 0;
}
void print(void)
{
    printf("Hello DAC"); 
}
