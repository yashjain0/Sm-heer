#include<iostream>

class Node
{
public:
	int data;
	Node *next;
};

class Stack
{
private:
	Node *top;
public:
	Stack(){top=NULL;}
	void push(int x);
	int pop();
	void Display();

};

void Stack::push(int x)
{
	Node *t= new Node;
	if(t==NULL)
	cout<<"Overflow";
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

int Stack::pop()
{
	int x=-1;
	
	if(Node==NULL)
	printf("Underflow");
	else
	{
		x=top->data;
		Node *t=top;
		top=top->next;
		delete t;
	}
	return x;
}

void stack::Display()
{
	Node *p=top;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	Stack stk;
	stk.push(10);
	stk.push(20);

	stk.Display;
	return 0;
}








