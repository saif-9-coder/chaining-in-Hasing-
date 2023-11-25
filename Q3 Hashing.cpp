#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define max_size 100000
using namespace std;
struct node
{
    int data;
    struct node *next;
};

 class hashing{
 	node *linklist[max_size];
 	public:
 		hashing()
 		{
 			linklist[max_size]=NULL;//{NULL} is written by GR 
		}
		void init(int);
		void insert(int,int);
		void display(int);
		void search(int);
 };

void hashing::display(int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        struct node *temp = linklist[i];
        cout<<"\t\t\t\tlinklist["<<i<<"]-->";
        while(temp!=NULL)
        {
        	cout<<temp->data<< "-->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

void hashing::init(int n)
{
    int i;
    for(i = 0; i < n; i++)
        linklist[i] = NULL;
}

void hashing::insert(int value,int n)
{
    //create a newnode with value
    struct node *newNode = new node();
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % n;

    //check if linklist[key] is empty
    if(linklist[key] == NULL)
        linklist[key] = newNode;
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = linklist[key];
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}
void hashing::search(int n) 
{
	int value;
	cout<<"\t\t\t\tEnter a Value to Search:";cin>>value;
 	int key = value % n;
    node *temp = linklist[key];
    while(temp!=NULL)
    {
        if(temp->data == value)
        	{
		   		cout<<"\t\t\t\tYour Searched Value|"<<value<<"| Found="<<temp->data<<endl<<endl;return;
			}
        temp = temp->next;
    }
    cout<<"\t\t\t\tYour Searched value |'"<<value<<"'| Not Found\n"<<endl;
}

int main()
{
	
		hashing c1;
	int i,m,n;
	cout<<"\t\t\t\tEnter number of times you want to insert values:";
	cin>>n;
    c1.init(n);
	for(i=1;i<=n;i++)
	{
		cout<<"\t\t\t\tEnter a value for "<<i<<"-time:";
		cin>>m;
		c1.insert(m,n);
	}
	c1.display(n);
	c1.search(n);
		getch();
}
