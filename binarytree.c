#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *left,*right;
};
struct node * create(struct node *root,int n)
{
	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->info=n;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(n>root->info)
	root->right=create(root->right,n);
	else
	root->left=create(root->left,n);
	return root;
}
void preorder(struct node *r)
{
	if(r!=NULL)
	{
		printf("%4d",r->info);
		preorder(r->left);
		preorder(r->right);
	}
}
void inorder(struct node *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf("%4d",r->info);
		inorder(r->right);
	}
}
void postorder(struct node *r)
{
	if(r!=NULL)
	{
		postorder(r->left);
		postorder(r->right);
		printf("%4d",r->info);
		
	}
}
int main()
{
	struct node *root=NULL;
	int x[]={90,36,58,96,32,92,12,93,24,97,38,60,98},n=13,i;
	for(i=0;i<n;i++)
	{
		root=create(root,x[i]);
	}
	printf("\n Preorder :\n");
	preorder(root);
	printf("\n Inorder :\n");
	inorder(root);
	printf("\n Postorder :\n");
	postorder(root);
	
}