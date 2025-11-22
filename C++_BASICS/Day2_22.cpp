#include<iostream> 

using namespace std; 

class Complex 
{
    private: 
    int real ; // 4 
    int imag;  // 4 
    public: 
    //classname * const this; 
    //Complex * const this;  
    //this = &c1; 
    void initComplex( void )
    {
        this->real = 0; 
        this->imag = 0; 
    }
    //setter / mutator 
    void setReal(int real)
    {
        this->real = real; 
    }
    void setImag(int imag)
    {
        this->imag = imag; 
    }
    //getter / inspector 
    int getReal( void )
    {
        return this->real; 
    }
    int getImag( void )
    {
        return this->imag; 
    }


    //this = &c1 
    void acceptRecord( void )
    {
        cout<<"Real : ";
        cin>>this->real;  
        //cin>>real; 
        cout<<"Imag : "; 
        cin>>this->imag; 
        //cin>>imag; 
    }
    //facilitator 
    //this = &c1 
    void printRecord( void )
    {
        cout<<"Real : "<<real <<endl; 
        cout<<"Imag : "<<imag <<endl; 
    }
}; 
int main(int argc, char const *argv[])
{
    Complex c1; 
    c1.initComplex( ); // c1.initComplex(&c1);  
    c1.acceptRecord( ); //10 20 c1.acceptRecord(&c1) 
    c1.initComplex( ); //c1.initComplex(&c1); 
    c1.setReal(100); 
    c1.setImag(200); 
    c1.printRecord( ); 
    return 0;
}

int main1(int argc, char const *argv[])
{
    Complex c1;
    c1.initComplex( );  // c1.initComplex(&c1); 
    c1.acceptRecord( ); // c1.acceptRecord(&c1); 
    c1.setReal(100); // c1.setReal(100 , &c1); 
    c1.printRecord( );  //c1.printRecord(&c1);  

     
    return 0;
}
