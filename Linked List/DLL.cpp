#include<stdio.h>
#include<stdlib.h>


struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first Null;


void Create(int A[], int n)
{
	struct Node *t, *last;
	int i;

	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->prev=NULL;
	first->next=NULL;
	last=first;

	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
}

void Display( struct Node *p)
{
	while(p)
	{
		printf("%d", p->data);
		p=p->next;
	}
	printf("\n")
}


void Length( struct Node *p)
{
	int l=0
	while(p)
	{
		l++;
		p=p->next;
	}
	return l;
}

void Insert(struct Node *p,int x,int index)
{
	struct Node *t;
	int i;

	if(index<0||index>length(p))
	{
		return;
	}
	if(index==0)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		t->prev=NULL;
		t->next=p;
		p->prev=t;
		first=t;

	}
	else
	{	t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		for(i=0;i<index-1;i++)
		{
			p=p->next;
		}
		t->next=p->next;
		t->prev=p;
		if(p->next)
			p->next->prev=t;
		p->next=t;
	}
}

void Reverse1(struct Node *p)
{
 int *A,i=0;
 struct Node *q=p;

 A=(int *)malloc(sizeof(int)*count(p));

 while(q!=NULL)
 {
 A[i]=q->data;
 q=q->next;
 i++;
 }
 q=p;
 i--;
 while(q!=NULL)
 {
 q->data=A[i];
 q=q->next;
 i--;
 }
}
void Reverse2(struct Node *p)
{
 struct Node *q=NULL,*r=NULL;

 while(p!=NULL)
 {
 r=q;
 q=p;
 p=p->next;
 q->next=r;
 }
 first=q;
}
void Reverse3(struct Node *q,struct Node *p)
{
 if(p)
 {
 Reverse3(p,p->next);
 p->next=q;
 }
 else
 first=q;
}

int main()
{
	int A[]={10,20,30,40,50};
	Create(A,5);
	printf("\nLength is %d\n",Length(first));
	Display(first);

	return 0;
}

