#include<iostream>
using namespace std;

class Node 
{
	public:
	Node *next;
	Node *prev;
	int data;
	Node()
	{
		next=NULL;
		prev=NULL;
	}
};

class dlinklist
{
	Node *head;
	Node *tail;
	public:
	dlinklist()
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

void dlinklist::insert(int value)
{
	Node *ptr=new Node;
	ptr->data=value;
	if (head==NULL)
	{head=ptr;}
	else
	{ptr->prev=tail;
	 tail->next=ptr;}
	tail=ptr;
}

void dlinklist::insertat(int pos,int value)
{
	if( pos>this->count() )
	cout<<"Linklist doesnot have this many elements"<<endl;
	else
	{
	Node *temp=new Node;
	temp->data=value;
	if (pos==1)
	{
		head->prev=temp;
		temp->next=head;
		temp->prev=NULL;
		head=temp;
	}
	else
	{	
		int i=1;
		Node *ptr=head;
		while(i<pos-1)
		{ptr=ptr->next;i++;}
		temp->prev=ptr;
		temp->next=ptr->next;
		ptr->next=temp;
		if(temp->next!=NULL)
		temp->next->prev=temp;
	}
	}
}

void dlinklist::del()
{
	Node *ptr=head;
	while(ptr->next!=tail)
	{ptr=ptr->next;}
	tail=ptr;
	ptr=ptr->next;
	tail->next=NULL;
	ptr->prev=NULL;
	delete ptr;
}

void dlinklist::delat(int pos)
{
	if( pos>this->count() )
	cout<<"Linklist Does not have that many elements"<<endl;
	else
	{
		Node *ptr=head;int i=1;
		while(i<pos)
		{ptr=ptr->next;i++;}
		
		if (ptr!=head)
		{ptr->prev->next=ptr->next;}
		
		if (ptr!=tail)
		{ptr->next->prev=ptr->prev;}
		
		ptr->next=NULL;
		ptr->prev=NULL;
		delete ptr;
		
	}
	
	
}

int dlinklist::count()
{
	Node *ptr=head;int i=0;
	while(ptr!=NULL)
	{
		i+=1;
		ptr=ptr->next;
	}
	return i;
}

void dlinklist::display()
{
	Node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<"NULL"<<endl;
}

int main()
{
	dlinklist dl;
	dl.insert(1);dl.insert(2);dl.insert(3);dl.insert(4);dl.insert(5);
	dl.display();
	dl.insertat(3,7);
	dl.display();
	dl.insertat(9,9);
	dl.del();
	dl.display();
	dl.delat(3);dl.display();	
	return 0;
}

