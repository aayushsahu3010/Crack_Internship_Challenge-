#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// global declaration
struct Employee // blue-print
{   
    //members 
    private: 
    char name[20]; // 20
    int empid;     // 4
    float salary;  // 4
    public: 
    void acceptRecord(/*struct Employee *ptr*/)
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

    struct Employee e1;
    e1.acceptRecord(); //e1.acceptRecord(&e1);
    //e1.salary = 0.0f;
    e1.printRecord(); //e1.printRecord(&e1);
    return 0;
}