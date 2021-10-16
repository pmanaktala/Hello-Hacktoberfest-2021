/*we have to find the Diameter of a binary tree (i.e. leaf node to leaf node maximum distance)  */
/*Here, I have used dynamic programming approach */

#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node* lchild;
	int data;
	struct node* rchild;

	node(int val)
	{
		lchild=rchild=NULL;
		data=val;
	}
};

int diameter(node* root,int &res)  //as a reference pass kia hai taaki main funciton mein value change ho jaaye
{
	if(root==NULL)
		return 0;
	int lh=diameter(root->lchild,res);
	int rh=diameter(root->rchild,res);
	
	int temp= 1+ max(lh,rh);       //for iteration and passing 
	int relation = 1+lh+rh;
	
	int ans = max(temp,relation);
	res = max(res,ans);

	return temp;
}

int main()
{
	struct node* root=new node(1);
	root->lchild=new node(2);
	root->rchild=new node(3);
	root->lchild->lchild=new node(4);
	root->lchild->rchild=new node(5);
	root->rchild->rchild=new node(7);
	root->lchild->rchild->lchild=new node(6);
	int res=INT_MIN;
	diameter(root,res);
	cout<<res<<endl;
	return 0;
}
