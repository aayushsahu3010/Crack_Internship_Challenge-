#include<iostream> 
using namespace std;
void sum(int num1 , double num2)
{
    double result = num1 + num2;
    cout<<"result : "<<result<<endl;  
    
}
void sum(double num1 , int num2)
{
    double result = num1 + num2; 
    cout<<"result : "<<result<<endl;  
    
}
int main( void )
{
    ::sum(10,20.33); 
    ::sum(20.33,10);  
    return 0; 
}
