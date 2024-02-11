#include<stdio.h>
#include<malloc.h>
struct Node
{
 int val;
 struct Node *next;
};
typedef struct Node N;
N *start=NULL,*ptr,*tmp;
void CreateNode();
void PrintNode();
void InsertFirst();
void InsertLast();
void CountNode();
void InsertAfter();
void InsertBefore();
void SearchNode();
void DeleteFirst();
void DeleteLast();
void DeleteAfter();
void DeleteBefore();
void ReverseList();
void CreateNode()
{
 ptr=(N *) malloc (sizeof(N));
 printf("Enter Value:");
 scanf("%d",&ptr->val);
 ptr->next=NULL;
 if(start==NULL)
 {
  start=ptr;
  tmp=ptr;
 }
 else
 {
  tmp->next=ptr;
  tmp=ptr;
 }
}
void PrintNode()
{
 ptr=start;
 while(ptr!=NULL)
 {
  printf("%d -> ",ptr->val);
  ptr=ptr->next;
 }
}
void InsertFirst()
{
 ptr=(N *) malloc (sizeof(N));
 printf("Enter Value:");
 scanf("%d",&ptr->val);
 ptr->next=start;
 start=ptr;
}
void InsertLast()
{
 tmp=start;
 while(tmp->next!=NULL)
 {
  tmp=tmp->next;
 }
 ptr=(N *) malloc (sizeof(N));
 printf("Enter Value:");
 scanf("%d",&ptr->val);
 ptr->next=NULL;
 tmp->next=ptr;
}
void CountNode()
{
 int c=0;
 ptr=start;
 while(ptr!=NULL)
 {
  ptr=ptr->next;
  c++;
 }
 printf("Number of nodes %d",c);
}

void InsertAfter()
{
 int n;
 printf("Enter value after which to insert:");
 scanf("%d",&n);
 tmp=start;
 while(tmp->val!=n)
 {
  tmp=tmp->next;
 }
 ptr=(N *) malloc (sizeof(N));
 printf("Enter Value:");
 scanf("%d",&ptr->val);
 ptr->next=tmp->next;
 tmp->next=ptr;
}
void InsertBefore()
{
 int n;
 N *prev;
 printf("Enter value before which to insert:");
 scanf("%d",&n);
 tmp=start;
 while(tmp->val!=n)
 {
  prev=tmp;
  tmp=tmp->next;
 }
 ptr=(N *) malloc (sizeof(N));
 printf("Enter Value:");
 scanf("%d",&ptr->val);
 ptr->next=tmp;
 prev->next=ptr;
}

void SearchNode()
{
 int n,flag=0,c=0;
 printf("Enter value to search:");
 scanf("%d",&n);
 ptr=start;
 while(ptr!=NULL)
 {
  c++;
  if(ptr->val==n)
  {
   flag=1;
   break;
  }
  ptr=ptr->next;
 }
 if(flag==1)
  printf("%d is found at location %d",n,c);
 else
  printf("%d not found",n);
}
void DeleteFirst()
{
 ptr=start;
 if(ptr==NULL)
 {
  printf("List Empty");
  return;
 }
 printf("Node %d is deleted.",ptr->val);
 start=start->next;
 free(ptr);
}
void DeleteLast()
{
 N *prev;
 ptr=start;
 if(ptr==NULL)
 {
  printf("List Empty");
  return;
 }
 while(ptr->next!=NULL)
 {
  prev=ptr;
  ptr=ptr->next;
 }
 printf("Node %d is deleted.",ptr->val);
 prev->next=NULL;
 free(ptr);
}
void DeleteAfter()
{
 int n;
 printf("Enter node value after which to delete:");
 scanf("%d",&n);
 ptr=start;
 while(ptr->val!=n)
 {
  ptr=ptr->next;
 }
 tmp=ptr->next;
 ptr->next=tmp->next;
 printf("%d is deleted.",tmp->val);
 free(tmp);
}
void DeleteBefore()
{
 int n;
 printf("Enter node value before which to delete:");
 scanf("%d",&n);
 ptr=start;
 while(ptr->next->val!=n)
 {
  tmp=ptr;
  ptr=ptr->next;
 }
 tmp->next=ptr->next;
 printf("%d is deleted.",ptr->val);
 free(ptr);
}
void ReverseList()
{
 N *pnode=NULL,*nnode=NULL;
 tmp=start;
 while(tmp!=NULL)
 {
  nnode=tmp->next;
  tmp->next=pnode;
  pnode=tmp;
  tmp=nnode;
 }
 start=pnode;
}

int main()
{
 int ch;
 do
 {
  printf("\n -: M E N U :-\n====================================");
  printf("\n1........Create Node.");
  printf("\n2........Print Node.");
  printf("\n3........Insert First.");
  printf("\n4........Insert Last.");
  printf("\n5........Count Node.");
  printf("\n6........Insert After.");
  printf("\n7........Insert Before.");
  printf("\n8........Search Node.");
  printf("\n9........Delete First.");
  printf("\n10.......Delete Last.");
  printf("\n11.......Delete After.");
  printf("\n12.......Delete Before.");
  printf("\n13.......Reverse List.");
  printf("\n0........Exit.");
  printf("\nEnter Choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:CreateNode();break;
   case 2:PrintNode();break;
   case 3:InsertFirst();break;
   case 4:InsertLast();break;
   case 5:CountNode();break;
   case 6:InsertAfter();break;
   case 7:InsertBefore();break;
   case 8:SearchNode();break;
   case 9:DeleteFirst();break;
   case 10:DeleteLast();break;
   case 11:DeleteAfter();break;
   case 12:DeleteBefore();break;
   case 13:ReverseList();break;
  }
 }
 while(ch!=0);
return 0;
}