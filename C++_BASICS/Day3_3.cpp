#include <iostream>
using namespace std;

class Time
{
private:
    int hrs;
    int mins;
    int secs;

public:
    //declarations 

    // this = &t1
    void input(void); 
    void display(void);
    // setter function
    void setHrs(int hrs);
    void setMins(int mins);
    void setSecs(int secs);
    // getter / inspector
    int getHours(void);
    int getMins(void);
    int getSecs(void);
    void incSecs(void);
};
//definations 
void Time :: input(void)
{
    cout << "Enter hrs , mins , secs";
    cin >> this->hrs >> this->mins >> this->secs;
}
void Time ::  display(void)
{
    cout << this->hrs << ":" << this->mins << ":" << this->secs << endl;
}
// setter function
void Time :: setHrs(int hrs)
{
    this->hrs = hrs;
}
void Time :: setMins(int mins)
{
    this->mins = mins;
}
void Time :: setSecs(int secs)
{
    this->secs = secs;
}
// getter / inspector
int Time ::  getHours(void)
{
    return this->hrs;
}
int Time :: getMins(void)
{
    return this->mins;
}
int Time :: getSecs(void)
{
    return this->secs;
}
void Time :: incSecs(void)
{
    this->secs++;
    if (this->secs == 60)
    {
        this->secs = 0;
        this->mins++;
        if (this->mins == 60)
        {
            this->mins = 0;
            this->hrs++;
            if (this->hrs == 24)
            {
                this->hrs = 0;
            }
        }
    }
}
int main()
{
    /*
        Time t1;
        t1.input( ); // t1.input(&t1); // 1 1 1
        t1.display( ); // t1.display(&t1); // 1 1 1
        //t1.hrs = 10;
        t1.setHrs(10);
        t1.display( ); // 10 1 1
        int hours;
        hours = t1.getHours( );
        cout<<"hrs : "<<hours;
   */
    /*
      Time t2;
      t2.setHrs(1);
      t2.setMins(1);
      t2.setSecs(1);
      t2.incSecs();
      t2.display( );
    */
    Time t3;
    t3.setHrs(22);
    t3.setMins(59);
    t3.setSecs(59);
    t3.incSecs();
    t3.display();

    return 0;
}
