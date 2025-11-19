#include <iostream>

using namespace std;

namespace na
{
    class Employee
    {
    private:
        char name[20];
        int empid;
        float salary;

    public:
        //declarartion 
        void acceptRecord(void);
        void printRecord(void);
    };
}
using namespace na; 
void Employee :: acceptRecord(void)
{
    cout << "Name : ";
    cin >> name;
    cout << "Empid : ";
    cin >> empid;
    cout << "Salary : ";
    cin >> salary;
}
void Employee :: printRecord(void)
{
    cout << "Name : " << name << endl;
    cout << "Empid : " << empid << endl;
    cout << "Salary : " << salary << endl;
}

int main(int argc, char const *argv[])
{
    //na::Employee emp;       // Instantiation
    Employee emp; 
    emp.acceptRecord(); // message passing
    emp.printRecord();  // message passing
    return 0;
}
