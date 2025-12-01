#include<iostream> 

using namespace std; 

inline int max( int a, int b)
{
    return a > b ? a : b; 
     
}
int main(int argc, char const *argv[])
{
    int res = max(10,20); 
    // a > b ? a : b; 
    cout<<"res : "<<res; 
    return 0;
}
