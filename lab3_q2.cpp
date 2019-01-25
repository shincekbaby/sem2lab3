#include<iostream>
using namespace std;

class Node 
{
	public:
	Node *next;
	int data;
	Node()
	{
		next=NULL;
	}
};

class clinklist
{
	Node *head;
	Node *tail;
	public:
	clinklist()
	{
		head=NULL;
		tail=NULL;
	}
	void insert(int value);
	void insertat(int pos,int value);
	void del();
	void delat(int pos);
	int count();
	void display();
};

void clinklist::insert(int value)
{
	Node *ptr=new Node;
	ptr->data=value;
	if (head==NULL)
	{head=ptr;}
	else
	{
	 tail->next=ptr;
	 ptr->next=head;
	}
	tail=ptr; 	
}

void clinklist::insertat(int pos,int value)
{
	if( pos>(this->count()+1) )
	cout<<"Sorry, Such a position does not exist"<<endl;
	else
	{
		Node *ptr=new Node;
		ptr->data=value;
		int i=1;Node *current=head;
		while(i<pos-1)
		{current=current->next;i++;}
		if(pos!=1)
		{
			ptr->next=current->next;
			current->next=ptr;
		}
		else if(pos==1)
		{
			ptr->next=current;
			head=ptr;
		}
	}
}

void clinklist::del()
{
	Node *ptr=head;
	while(ptr->next!=tail)
	{ptr=ptr->next;}
	tail=ptr;
	ptr=ptr->next;
	ptr->next=NULL;
	delete ptr;
	tail->next=head;
}

void clinklist::delat(int pos)
{
	if ( pos>this->count() )
	cout<<"The linklist does not contain that many elements";
	else 
	{	Node *ptr=head;
		int i=1;
		while(i<pos-1)
		{ptr=ptr->next;i++;}
	
		Node *d=ptr->next;
		ptr->next=d->next;
		d->next=NULL;
		delete d;
	}
}

int clinklist::count()
{
	Node *ptr=head;int i=1;
	while (ptr!=tail)
	{ptr=ptr->next;i++;}
	return i;
}

void clinklist::display()
{
	Node *ptr=head;
	while(ptr!=tail)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<ptr->data<<endl;
	
}

int main()
{
	clinklist cl;
	cl.insert(1);cl.insert(2);cl.insert(3);cl.insert(4);cl.insert(5);cl.insert(6);
	cl.display();
	cl.insertat(3,7);
	cl.display();
	cl.insertat(9,9);
	cl.del();
	cl.display();
	cl.delat(3);cl.display();
	return 0;
}
