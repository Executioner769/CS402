#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p, g, x, y, a, b, ka, kb;
    cout<<"Enter the value of p: ";
    cin>>p;
    cout<<"Enter the value of g: ";
    cin>>g;
    cout<<"Enter the value of x: ";
    cin>>x;
    cout<<"Enter the value of y: ";
    cin>>y;
    a = pow(g, x);
    a = a % p;
    b = pow(g, y);
    b = b % p;
    ka = pow(b, x);
    ka = ka % p;
    kb = pow(a, y);
    kb = kb % p;
    cout<<"The value of a is: "<<a<<endl;
    cout<<"The value of b is: "<<b<<endl;
    cout<<"The value of ka is: "<<ka<<endl;
    cout<<"The value of kb is: "<<kb<<endl;
    return 0;
}

// Input
/*
Enter the value of p: 23
Enter the value of g: 9
Enter the value of x: 4
Enter the value of y: 3
*/

// Output
/*
The value of a is: 6
The value of b is: 16
The value of ka is: 9
The value of kb is: 9
*/
