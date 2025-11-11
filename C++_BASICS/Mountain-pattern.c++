#include <bits/stdc++.h>
using namespace std;

void Reverse_mountain(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * (n - i) - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Alpha_Hill_Pattern(int n)
{
    /*  a
        a b a
       a b c b a
      a b c d c b a
    */
    for (int i = 0; i < n; i++)
    {
        for (int space = 0; space < n - i - 1; space++)
        {
            cout << " ";
        }
        char c = 'A';
        for (int j = 0; j <= i; j++)
        {
            cout << c << " ";
            c++;
        }
        c='A';
        for (int j = i; j >=1; j--)
        {
            cout<<c<<" ";
            c=c+j-1;
            // cout << char('A' + j - 1) << " ";
        }

        cout << endl;
    }
}


void Butterfly_pattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        for(int space =0;space<2*(n-i-1);space++){
            cout<<" ";
        }
        
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<"* ";
        }
        for(int space =0;space<2*(i+1);space++){
            cout<<" ";
        }
        
        for(int j=0;j<n-i-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}


void reverse_symeetric_pattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int space =0;space<2*(n-i-1);space++){
            cout<<" ";
        }
        
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void Symmetric_Void_Pattern(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n-i;j++){
            cout<<"*";
        }
        for(int space =0;space<i;space++){
            cout<<" ";
        }
        for(int space =0;space<i;space++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    reverse_symeetric_pattern(n);
}


void alpha_Traingle(int n ){
    for(int i=0;i<n;i++){
        char c='A';
        for(int j=0;j<=i;j++){
            cout<<char(c+n-j-1)<<" ";
        }
        cout<<endl;
    }

}
void numberCrownPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        for (int space = 0; space < (n + 1) - 2 * i; space++)
        {
            cout << " ";
        }
        for (int j = i; j >= 0; j--)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void mountain_pattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    Reverse_mountain(n);
}

void half_diamond(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Binary_number_traingle(int n)
{
    /*1
    0 1
    1 0 1
    0 1 0 1
    */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void Hollow_Rectangle(int n ){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j==0 || j==n-1){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    Hollow_Rectangle(3);
    // Alpha_Hill_Pattern(5);
    // numberCrownPattern(3);
    // // Binary_number_traingle(5);
// alpha_Traingle(3);
Butterfly_pattern(5);
// Symmetric_Void_Pattern(5);
    return 0;
}