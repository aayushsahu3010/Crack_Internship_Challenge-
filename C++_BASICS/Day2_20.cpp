#include<iostream> 
using namespace std;
int sum(int num1 , int num2)
{
    int result = num1 + num2;
    return result; 
    
}
// void sum(int num1 , int num2)
// {
//     double result = num1 + num2; 
//     cout<<"result : "<<result<<endl;  
    
// }
int main( void )
{
    int res = ::sum(10,20); 
    cout<<"Res : "<<res<<endl;  

    ::sum(30,40); 
    return 0; 
}
