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
