#include<iostream> 
using namespace std; 
class Complex
{
    private: 
    int real; 
    int imag; 
    public: 
    void acceptRecord( void )
    {
        cout<<"Real: "; 
        cin>>real; 
        cout<<"Imag : "; 
        cin>>imag;
        cout<<endl;  
    }
    void printRecord( void )
    {
        cout<<"Real : "<<real<<endl; 
        cout<<"Imag : "<<imag<<endl; 

        
    }
    //this = &c1 
    //other = c2
    Complex sum(Complex other)
    {
        Complex temp; 
        temp.real = this->real + other.real; 
        temp.imag = this->imag + other.imag; 
        return temp; 
    }
}; 
int main()
{
    Complex c1; 
    c1.acceptRecord( ); 

    Complex c2; 
    c2.acceptRecord(); 

    Complex c3; 
    //c3 = c1 + c2; 
    c3 = c1.sum(c2); // c1.sum(&c1 , c2) 
    c3.printRecord( ); 
    return 0;
}
