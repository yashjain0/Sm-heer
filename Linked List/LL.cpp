#include <stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	int i;
	struct Node *t, *last;
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

void display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}
}

void rdisplay(struct Node *p )
{
	if(p(!=NULL))
	{
		printf("%d",p->data);
		rdisplay(p->next);
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


int main()
{
	A[]={3,5,7,2,1};
	create(A,5);
	display(first);
	return 0;
}
