#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
//global declaration 
struct Employee // blue-print 
{
    char name[20]; //20 
    int empid; // 4 
    float salary; // 4 
};
// Global function 
void acceptRecord(struct Employee *ptr)
{
    printf("Name : "); 
    scanf("%s",ptr->name); 
    printf("Empid : "); 
    scanf("%d",&ptr->empid); 
    printf("Salary : "); 
    scanf("%f",&ptr->salary); 
}
void printRecord(struct Employee *ptr) 
{
    printf("Name : %s\n",ptr->name); 
    printf("Empid : %d\n",ptr->empid); 
    printf("Salary : %.2f\n",ptr->salary); 

}
int main(int argc, char const *argv[])
{
    
    struct Employee e1; 
    acceptRecord(&e1);
    e1.salary = 0.0f; 
    printRecord(&e1);  
    return 0;
}