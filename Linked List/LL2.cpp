void Reverse1( struct Node *p)
{
	int *A,i=0;
	A=(int*)malloc(sizeof(int)*count(p));


	struct Node *q;
	while(q!=NULL)
	{
		A[i]=p->data;
		p=p->next;
		i++;
	}
	p=first;
	i--;
	while(q!=NULL)
	{
		q->data=A[i];
		q=q->next;
		i--;
	}
}

void Reverse2( struct Node *p)
{
	struct Node *q=NULL,*r=NULL;

	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}

	first q;
}

void Reverse3( struct Node *q, struct Node *q)
{
	if(p!=NULL)
	{
		Reverse3(p,p->next);
		p->next=q;
	}
	else
		first=q;
}

void create2(int A[],int n)
{
 int i;
 struct Node *t,*last;
 second=(struct Node *)malloc(sizeof(struct Node));
 second->data=A[0];
 second->next=NULL;
 last=second;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void Merge(struct Node *p,struct Node *q)
{
 struct Node *last;
 if(p->data < q->data)
 {
 third=last=p;
 p=p->next;
 third->next=NULL;
 }
 else
 {
 third=last=q;
 q=q->next;
 third->next=NULL;
 }
 while(p && q)
 {
 if(p->data < q->data)
 {
 last->next=p;
 last=p;
 p=p->next;
 last->next=NULL;

 }
 else
 {
 last->next=q;
 last=q;
 q=q->next;
 last->next=NULL;

 }
 }
 if(p)last->next=p;
 if(q)last->next=q;

}
