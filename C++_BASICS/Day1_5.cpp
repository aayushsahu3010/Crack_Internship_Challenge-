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
int menuList( void )
{
    int choice; 
    printf("0.Exit\n"); 
    printf("1.AcceptRecord\n"); 
    printf("2.PrintRecord\n");
    printf("Enter the choice : "); 
    scanf("%d",&choice); 
    return choice; 
}
int main(int argc, char const *argv[])
{
    int choice; 
    struct Employee emp; 
    
    while((choice = menuList())!=0)
    {
        switch (choice)
        {
        case 1: 
            acceptRecord(&emp); 
            break;
        case 2: 
            printRecord(&emp); 
        }
    }

    return 0;
}