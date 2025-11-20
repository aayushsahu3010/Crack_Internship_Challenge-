#include<iostream> 
using namespace std;
void sum(int num1 , int num2)
{
    int result = num1 + num2;
    cout<<"result : "<<result<<endl;  
    
}
void sum(int num1 , int num2 , int num3)
{
    int result = num1 + num2 + num3;
    cout<<"result : "<<result<<endl;  
    
}
int main( void )
{
    ::sum(10,20); 
    ::sum(10,20,30);  
    return 0; 
}
