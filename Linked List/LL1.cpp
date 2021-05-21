struct Node * LSearch(struct Node *p,int key)
{
 struct Node *q;

 while(p!=NULL)
 {
 if(key==p->data)
 {
 q->next=p->next;
 p->next=first;
 first=p;
 return p;
 }
 q=p;
 p=p->next;
 }
 return NULL;

}

#to insert a node
void Insert(struct Node *p,int index,int x)
{
 struct Node *t;
 int i;
 
 if(index < 0 || index > count(p))
 return;
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;
 //to insert at the start
 if(index == 0)
 {
 t->next=first;
 first=t;
 }
 //other than last
 else
 {
 for(i=0;i<index-1;i++)
 p=p->next;
 t->next=p->next;
 p->next=t;

 }
}


void SortedInsert(struct Node *p,int x)
{
 struct Node *t,*q=NULL;
 
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=x;
 t->next=NULL;

 if(first==NULL)
 first=t;
 else
 {
 while(p && p->data<x)
 {
 q=p;
 p=p->next;
 }
 if(p==first)
 {
 t->next=first;
 first=t;
 }
 else
 {
 t->next=q->next;
 q->next=t;
 }
 }

}



void Insert(struct Node *p,int index,int x)
{
 struct Node *t;
 int i;

 if(index < 0 || index > count(p))
 return;
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=x;

 if(index == 0)
 {
 t->next=first;
 first=t;
 }
 else
 {
 for(i=0;i<index-1;i++)
 p=p->next;
 t->next=p->next;
 p->next=t;

 }
}

int delete( struct Node *p, int index)
{
	int i,x=-1;
	struct Node *q=NULL;

	if(index<1|| intdex>count(p))
	{
	return -1;
	}

	if(index==1)
	{
		q=first;
		x=first->data;
		first=first->next;
		free(q);
		return x;
	}

	else()
	{
		for(i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		free(p);
		return x;
	}
}


int isSorted(struct Node *p)
{
	int x=first->data;

	while(p!=NULL)
	{
		if(p->data < x)
		{
			return 0;
		}
		x=p->data;
		p=p->next;
	}
	return 1;
}
