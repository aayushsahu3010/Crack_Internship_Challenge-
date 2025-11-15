#include<stdio.h> 

namespace na
{
    int num1 = 10; 
    void print( )
    {
        printf("num1 : %d",num1) ; // allowed same scope 
    }  
    struct Point 
    {
        int xPos; 
        int yPos;
        void print( void )
        {
            printf("xPos : %d\n",xPos); 
            printf("yPos : %d\n",yPos); 
        } 
    }; 
    namespace nb
    {
        int num3 = 30; 
    }
} 
int main(int argc, char const *argv[])
{
    //na::Point pt = {10,20}; 
    //pt.print( ); 
    using namespace na; 
    Point pt1 = {10,20}; 
    pt1.print( ); 
    return 0;
}

