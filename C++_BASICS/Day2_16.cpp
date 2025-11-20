#include<iostream> 
using namespace std;
//In procedure oriented we cannot give same name to the function 
// If implementation of function is logical same or equivalent we can give same name to function 

void sum(int num1 , double num2)
{
    double result = num1 + num2;
    cout<<"result : "<<result<<endl;  
    
}
void add(int num1 , int num2)
{
    int result = num1 + num2;
    cout<<"result : "<<result<<endl;  
    
}
int main( void )
{
    ::add(10,20); 
    ::sum(10,11.33); 
    return 0; 
}
