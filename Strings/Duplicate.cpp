/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char A[]="tootaa";
    long int H=0;
    int x;
    
    for(int i=0;A[i]!='\0';i++)
    {
        x=1;
        x=x<<(A[i]-97);
        cout<<x<<endl;
        if(x&H>0)
        {cout<<"duplicate "<<A[i]<<endl;}
        else
        H=x|H;
    }
    

    return 0;
}
