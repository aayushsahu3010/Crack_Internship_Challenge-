#include<iostream> 
using namespace std; 
//Step1: Understand requirement and Declare the class
class Date 
{
    //Step2: Declare the data-members 
    //Step4: access specfier 
    private:
    int day; 
    int month; 
    int year; 
    public: 
    void acceptDate( void )
    {
        cout<<"Day : "; 
        cin>>day; 
        cout<<"Month : "; 
        cin>>month; 
        cout<<"Year : "; 
        cin>>year; 
    }
    void printDate( void )
    {
        // cout<<"Day : "<<day<<endl; 
        // cout<<"Month : "<<month<<endl;
        // cout<<"Year : "<<year<<endl;  
        cout<<day<<"/"<<month<<"/"<<year; 
    }
}; 

int main(int argc, char const *argv[])
{
    //Step3: Creating the Object
    Date dt1; 
    //Step5: calling methods
    dt1.acceptDate( );
    dt1.printDate( );  

    return 0;
}



//Step5: calling methods