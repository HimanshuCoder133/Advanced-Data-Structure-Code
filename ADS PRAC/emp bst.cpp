#include<iostream>
#include<string>

using namespace std;
#define max 20
int cnt=0;
class tree
{
	public:
	int salary,emp_id,cnt,cnt1,cnt2;
	string ename,gen,dept;
	tree *lc,*rc;
	
	void create();
	void insert(tree *root,tree *next);
	void display(tree *root);
	void height();
	void leaf(tree *root);
		
}*root,*stack[max],*temp;

void tree::create()
{
	int ch;
	tree *next;
	root=new tree;
	cout<<"\nENTER the Employee INFORMATION: ";
	cout<<"\nEnter Id: ";
	cin>>root->emp_id;
	cout<<"\nEnter NAME: ";
	cin>>root->ename;
	cout<<"Enter DEPARTMENT: ";
	cin>>root->dept;
	cout<<"Enter GENDER: ";
	cin>>root->gen;
	cout<<"Enter SALARY: ";
	cin>>root->salary;
	
	cnt=cnt1=cnt2=1;
	root->lc=root->rc=NULL;
	cnt++;
	do{
		cout<<"Do you want to add new Member (0/1)no/yes?: ";
		cin>>ch;
		if(ch==1)
		{
			next=new tree;
			cout<<"\nEnter the data for new Member: ";
			
			cout<<"\nEnter Id: ";
			cin>>next->emp_id;
			cout<<"\nEnter NAME: ";
			cin>>next->ename;
			cout<<"Enter DEPARTMENT: ";
			cin>>next->dept;
			cout<<"Enter GENDER: ";
			cin>>next->gen;
			cout<<"Enter SALARY: ";
			cin>>next->salary;
			
			next->lc=next->rc=NULL;
			insert(root,next);
		}
		
	}while(ch==1);
	
}
void tree::insert(tree *root,tree *next)
{
	 char chr;
	 tree *temp;
	 if(root->salary > next->salary)
	 {
	 	if(root->lc==NULL)
	 	{
	 		root->lc=next;
	 		cnt1++;
	 	}
	 	else
	 	{
	 		insert(root->lc,next);
	 	}
	 	
	 }
	 if(root->salary < next->salary)
	 {
	 	if(root->rc==NULL)
	 	{
	 		root->rc=next;
	 		cnt2++;
	 	}
	 	else
	 	{
	 		insert(root->rc,next);
	 	}
	 }
}
	 

void tree::height()
{
	if(cnt1>=cnt2)
	{
		cout<<"The HEIGHT of COMPANY: "<<cnt1;
		
	}
	else
	{
		cout<<"The HEIGHT of COMPANY: "<<cnt2;
	}
}


void tree::leaf(tree *root)
{
	
	int top=-1;
	temp = root;
	if(root!=NULL)
	{
		do
		{
			while(temp!=NULL)
			{
				top++;
				stack[top]=temp;
				temp=temp->lc;
			}
			if(top!=-1)
			{
				temp=stack[top];
				if(temp->lc==NULL && temp->rc==NULL)
				{				
					
					cout<<temp->emp_id<<"\t\t"<<temp->ename<<"\t\t"<<temp->dept<<"\t"<<temp->gen<<"\t"<<temp->salary<<endl;
				}
				temp=temp->rc;
				top--;
			}
		}while(top!=-1 || temp !=NULL);
	}
}

void tree::display(tree *root)
{

	if(root==NULL)
	{
		return;
	}
	else
	{
		
		cout<<root->emp_id<<"\t\t"<<root->ename<<"\t\t"<<root->dept<<"\t"<<root->gen<<"\t"<<root->salary<<endl;
		
		display(root->lc);
		display(root->rc);
	}
}

int main()
{
	int ch;
	tree t;
	
	do{
		cout<<"\n\nEnter your Choice: ";
		cout<<"\n1. ADD the Employees";
		cout<<"\n2. DISPLAY the Employee";
		cout<<"\n3. TOTAL Height of the tree";
		cout<<"\n4. Current Employee info";
		cout<<"\n5. EXIT\n";
		
		cin>>ch;
		
		switch (ch) 
		{
			case 1:
				t.create();
				break;
				
			case 2:
				cout<<"EMP ID \t\t NAME\t\t DOB \t\t GENDER \t SALARY\n";
				t.display(root);
				break;
				
			case 3:
				t.height();
				break;
			
			case 4:
				cout<<"EMP ID \t\t NAME \t\t DOB \t\t GENDER \t SALARY\n";
				t.leaf(root);
				break;
					
			case 5:
				exit(0);
				
			default:
				cout<<"Invalid Choice!!";
				break;
		}
	}while(ch!=6);
		
	return 0;
}			
