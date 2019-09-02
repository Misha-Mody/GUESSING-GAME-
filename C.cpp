#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

struct TreeNode{
	string data;
	TreeNode *left;
    TreeNode *right;
};
class BinaryTree{
	private:
		TreeNode *root;
	

	public:
		BinaryTree()
		{
			root=NULL;
			begin(root);
		}
		void begin(TreeNode *&);
		void win();
		void lose(TreeNode *&,TreeNode *&);
					
};

void BinaryTree::begin(TreeNode *& tree)
{
	system("COLOR FS");
	char ch,ch1,ch2;
	if(tree!=NULL)
{

		cout<<"\t\t\t";
		cout<<tree->data<<"\n ";
		cin>>ch;
		if(ch=='N'||ch=='n')
		{
			if(tree->right!=NULL)
			{				
			  if(tree->right->left==NULL && tree->right->right==NULL)

				{
					cout<<"\t\t\t";
					cout<<"\nIs it "<<tree->right->data<<" ?";
				    cin>>ch1;
					if(ch1=='Y'||ch1=='y')
					{
						system("COLOR 5F");
						win();
					}
					else
					{
						system("COLOR 20");
						lose(tree,tree->right);
					}
			    }
				else
				{   system("COLOR F5");
				    begin(tree->right);	
				}
				
				
			}
			else
			{
				system("COLOR 20");
				lose(tree->right,tree);
			}
		}
		else
		{ 
		
 
		    if(tree->left!=NULL)
		    {
		    	if(tree->left->left!=NULL)
		    	{
		    		
		    		system("COLOR F5");
		    		begin(tree->left);
					}
	
				 else {
					cout<<"\t\t\t";
					cout<<"\nIs it "<<tree->left->data<<" ?";
					cin>>ch2;
					if(ch2=='Y'||ch2=='y')
					{
						system("COLOR 5F");
						win();
					}
					else
					{
						system("COLOR 20");
						lose(tree,tree->left);
					}
				}
			}
			 
		else
			 {
				system("COLOR 20");
				lose(tree->left,tree);
				
			}
			
	             	
	}
    
	}
	else
	{
		system("COLOR 20");
		lose(tree,tree);
	}
}

void BinaryTree::win()   //line 84
{
char ch;
system("COLOR 5F");
cout<<"\t\t\t";
cout<<"\nI win !\n"<<endl;
cout<<"\t\t\t";
cout<<"\nPlay again ?[Y/N]\n";
cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		system("COLOR 5F");
		cout<<endl;
		begin(root);
	}
	else
	{
		cout<<"\n\t\t\t\t\t\t\t\t";
		cout<<"********** THANK YOU FOR PLAYING ***************";
	}
}

void BinaryTree::lose(TreeNode *&tree,TreeNode *&tree2)
{
	string question;
    string answer;
	char ch,ch2;
	TreeNode* oneNode=new TreeNode;
	TreeNode* twoNode=new TreeNode;
	
	if(root==NULL)
	{
		cout<<"\n\t\t";
		cout<<"******************** I KNOW NOTHING YET  ***********"<<endl<<endl;
		cout<<"\n\t\t";
		cout<<"Think and give me a person,place or thing\n";
		getline(cin,answer);
	}
	else{
		cout<<"\t\t\t\t";
		cout<< "I give up."<<endl;
		cout<<"\t\t\t\t";
		getline(cin,answer);
		cout<<"What is it?Please tell me \n";
		getline(cin,answer);
	}
	if(tree !=NULL)
	{
		cout<<"\n\t\t";
		cout<<"I need a question to distinguish "<<answer<<" from a\an "<<tree2->data<<".\n";
	}
	else if(root!=NULL)
	{
		cout<<"\n\t\t";
		if(tree2->left!=NULL)
		{
			if(tree2->left->left==NULL)
			{
			  cout<<"I need a question to distinguish "<<answer<<"from a\an"<<tree2->left->data<<".\n";
			}
		}
	}
	else{
		cout<<"\n\t\t";
		cout<<"I need a question for me to know what that is\n";
	}
	
	cout<<"\n\t\t";
	cout<<"Enter the question\n";
	getline(cin,question);
	cout<<"\n\t\t";
	cout<<"If answer were "<<answer<<" the answer would be? \n";
    cin>>ch;
	
	if(tree!=NULL)
	{
		oneNode->data=question;
		if(ch=='y'||ch=='Y')
		{
			oneNode->right=tree2;
			
			oneNode->left=twoNode;
		}
		
		else{
			oneNode->left=tree2;
			oneNode->right=twoNode;
		}
		tree2=oneNode;
		twoNode->data=answer;
		twoNode->right=twoNode->left=NULL;
	}
	else
{
	tree=oneNode;
	oneNode->data=question;
	if(ch=='Y'||ch=='y')
	{
		oneNode->right=NULL;
		oneNode->left=twoNode;
		
	}
	else
	{
		oneNode->left=NULL;
		oneNode->right=twoNode;
		
	}
	twoNode->data=answer;
	twoNode->left=twoNode->right=NULL;
	
}

if(root==NULL)
{
	root=tree;
}

cout<<"\t\t\t";
cout<<"Play Again ?(y/n)";
cin>>ch2;
cout<<endl;
if(ch2=='Y'||ch2=='y')
 begin(root);
 
 else
 {
 	cout<<"\n\t\t\t";
 	cout<<"************THANK YOU FOR PLAYING***********";
 	
 }


}

void instructions()
{
	system("COLOR D0");
	cout<<"****************HELLO AND WELCOME TO THE GUESSING GAME****************\n\n\n";
	cout<<"INSTRUCTIONS\n";
	cout<<"1.THINK OF A WORD\n 2.THE COMPUTER WILL TRY TO GUESS IT BY ASKING YES OR NO QUESTIONS\n";
	cout<<"3.THE COMPUTER WILL KEEP TRYING TILL IT WINS OR GIVES UP\n";
	cout<<"4.IF THE COMPUTER GIVES UP,IT WILL STORE THE WORD IN TREE AND A RELATABLE QUESTION TO IT\n";
	
	
}
int main()
{
	instructions();
	BinaryTree guessingGame;
	
	return 0;
}






