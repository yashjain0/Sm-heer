#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
void RDisplay(struct Node *p)
{
 if(p!=NULL)
 {
 RDisplay(p->next);
 printf("%d ",p->data);

 }
}


int count(struct Node *p)
{
	int l=0;
	while(p)
	{
		l++;
		//for sum
		//s=s+p->data;
		p=p->next;
	}
	return l;
}

int max(struct Node *p)
{
    int Max_int=p->data;
    p=p->next;
    while(p)
    {
        if(p->data>Max_int)
        {
            Max_int=p->data;
        }
        p=p->next;
    }
    return Max_int;
}

int main()
{
	A[]={3,5,7,2,1};
	create(A,5);
	display(first);
	return 0;
	cout<<endl<<max(first);
}
