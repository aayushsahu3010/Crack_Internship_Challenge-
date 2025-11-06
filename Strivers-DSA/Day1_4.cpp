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
    printRecord(&e1);  
    return 0;
}
int main5(int argc, char const *argv[])
{
    //local declaration 
    struct Employee // blue-print 
    {
        char name[20]; //20 
        int empid; // 4 
        float salary; // 4 
    };
    //int *ptr = (int*)malloc(sizeof(int));
    struct Employee *ptr = (struct Employee*)malloc(sizeof(struct Employee)); 
    printf("Name : "); 
    scanf("%s",ptr->name); 
    printf("Empid : "); 
    scanf("%d",&ptr->empid); 
    printf("Salary : "); 
    scanf("%f",&ptr->salary); 

    printf("Name : %s\n",ptr->name); 
    printf("Empid : %d\n",ptr->empid); 
    printf("Salary : %.2f\n",ptr->salary); 

    free(ptr); // TO avoid memory leakage 
    ptr = NULL; // TO avoid dangling pointer 

   
    return 0;
}
int main4(int argc, char const *argv[])
{
    //local declaration 
    struct Employee // blue-print 
    {
        char name[20]; //20 
        int empid; // 4 
        float salary; // 4 
    };
    struct Employee e1;  
    printf("Name : "); 
    scanf("%s",e1.name); 
    printf("Empid : "); 
    scanf("%d",&e1.empid); 
    printf("Salary : "); 
    scanf("%f",&e1.salary); 

    printf("Name : %s\n",e1.name); 
    printf("Empid : %d\n",e1.empid); 
    printf("Salary : %.2f\n",e1.salary); 

   
    return 0;
}
int main3(int argc, char const *argv[])
{
    //local declaration 
    struct Employee // blue-print 
    {
        char name[20]; //20 
        int empid; // 4 
        float salary; // 4 
    }; 
    // Type : struct Employee 
    // variable / object : e1 
    struct Employee e1; 
    e1.empid = 1; 
    //e1.name = "Ketan"; 
    strcpy(e1.name,"Ketan");
    e1.salary = 1000.00f;  

    printf("Name : %s\n",e1.name); 
    printf("Empid : %d\n",e1.empid); 
    printf("Salary : %.2f\n",e1.salary); 
    return 0;
}
int main2(int argc, char const *argv[])
{
    //local declaration 
    struct Employee // blue-print 
    {
        char name[20]; //20 
        int empid; // 4 
        float salary; // 4 
    }; 
    // Type : struct Employee 
    // variable / object : e1 
    struct Employee e1 = {"Ketan",1,1000.00f}; 
    
    printf("Name : %s\n",e1.name); 
    printf("Empid : %d\n",e1.empid); 
    printf("Salary : %.2f\n",e1.salary); 
    return 0;
}

int main1()
{
    char name[20];
    int empid; 
    float salary; 
    
    printf("Name : "); 
    scanf("%s",name); 
    printf("Empid : "); 
    scanf("%d",&empid); 
    printf("Salary : "); 
    scanf("%f",&salary); 

    printf("Name : %s\n",name); 
    printf("Empid : %d\n",empid); 
    printf("Salary : %.2f\n",salary); 
    return 0;
}
