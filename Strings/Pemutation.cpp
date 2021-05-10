#include<bits/stdc++.h>
using namespace std;

void perm(char s[], int k)
{
	static int A[10]={0};
	static char Res[10];
	int i;
	if(s[k]=='\0')
	{
		Res[k]='\0';
		printf("%s\n",Res);
	}
	else
	{
		//if i comes to end, then A[i]=0, and go back to previous call and start from next.
		for(i=0;s[i]!='\0';i++)
		{
			if(A[i]==0)
			{
				//when s[k]=="\0" that is k comes to end print the string.
				Res[k]=s[i];
				A[i]=1;
				perm(s,k+1);
				A[i]=0;
			}
		}
	}

}
int main()
{
	char s[]="ABC";
	perm(s,0);
	return 0;
}
