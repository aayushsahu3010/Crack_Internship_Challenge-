#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// global declaration
int x; 
class Employee // blue-print
{   
    //data-members / fields / attributes / properties 
    private: 
    char name[20]; // 20
    int empid;     // 4
    float salary;  // 4
   
    public: 
    //member functions / methods / behaviour / message 
    void acceptRecord()
    {
        printf("Name : ");
        scanf("%s", name);
        printf("Empid : ");
        scanf("%d", &empid);
        printf("Salary : ");
        scanf("%f", &salary);
    }
    void printRecord(/*struct Employee *ptr*/)
    {
        printf("Name : %s\n",name);
        printf("Empid : %d\n",empid);
        printf("Salary : %.2f\n", salary);
    }
};


int main(int argc, char const *argv[])
{

    Employee e1;
    //e1 -> object 
    e1.acceptRecord(); //e1.acceptRecord(&e1);
    //e1.salary = 0.0f; // NA 
    e1.printRecord(); //e1.printRecord(&e1);
    
    //e1.Employee::acceptRecord( ); 
    //e1.Employee::printRecord( ); 
    
    return 0;
}