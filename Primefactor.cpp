#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int* primeFactors(int n)
{
    int *A;
    A=(int*)malloc(100*sizeof(int));
    int j=0;
    while (n % 2 == 0)
    {
        A[j]=2;
        n = n/2;
        j++;
    }
    
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            A[j]=i;
            n = n/i;
            j++;
        }
    }
    if (n > 2)
        A[j]=n;
    return A;
}

int main()
{
int t;
cin>>t;
while(t--)
{
	int n,m,total;
	int *C;
	int B=0;
	cin>>n>>m;
	total=n-1;
	
	C=primeFactors(m);
	/* N=sizeof(C)/sizeof(int);
	for(int i=0;i<N;i++)
	{
	    cout<<C[i]<<",";
	}
	cout<<endl;
	*/
	for(int i=0;C[i]<=n;i++)
	{
		if(C[i]!=0 && m%C[i]==0)
		{
			B++;
		}
	}
	total=total+B*(B-1)*0.5;
	cout<<total<<endl;
}
}
