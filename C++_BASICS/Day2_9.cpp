#include <stdio.h>
namespace na
{
    int num1 = 10;
}
using namespace na;

namespace nb
{
    void showRecord(void)
    {
        // using namespace na;
        // printf("num1 : %d\n",na::num1);
        printf("num1 : %d\n", num1);
    }
    void printRecord(void)
    {
        // using namespace na;
        printf("num1 : %d\n", num1);
    }
    void displayRecord(void)
    {
        // using namespace na;
        printf("num1 : %d\n", num1);
    }
}

int main(int argc, char const *argv[])
{
    nb::showRecord();
    nb::printRecord();
    nb::displayRecord();
    return 0;
}
/*
namespace na
{
    int num1 = 10;
}
using namespace na;
void showRecord( void )
{
    //using namespace na;
    //printf("num1 : %d\n",na::num1);
    printf("num1 : %d\n",num1);
}
void printRecord( void )
{
    //using namespace na;
    printf("num1 : %d\n",num1);
}
void displayRecord( void )
{
    //using namespace na;
    printf("num1 : %d\n",num1);
}

int main(int argc, char const *argv[])
{
    ::showRecord( );
    ::printRecord( );
    ::displayRecord( );
    return 0;
}
*/
/*
namespace na
{
    int num1 = 10;
}
void showRecord( void )
{
    using namespace na;
    //printf("num1 : %d\n",na::num1);
    printf("num1 : %d\n",num1);
}
void printRecord( void )
{
    using namespace na;
    printf("num1 : %d\n",num1);
}
void displayRecord( void )
{
    using namespace na;
    printf("num1 : %d\n",num1);
}

int main(int argc, char const *argv[])
{
    ::showRecord( );
    ::printRecord( );
    ::displayRecord( );
    return 0;
}
*/
/*
namespace na
{
    int num1 = 10;
}
void showRecord( void )
{
    printf("num1 : %d\n",na::num1);
}
void printRecord( void )
{
    printf("num1 : %d\n",na::num1);
}
void displayRecord( void )
{
    printf("num1 : %d\n",na::num1);
}

int main(int argc, char const *argv[])
{
    ::showRecord( );
    ::printRecord( );
    ::displayRecord( );
    return 0;
}
*/