#include<stdio.h>
#include<malloc.h>
struct Node
{
 int val;
 struct Node *prev;
 struct Node *next;
};
typedef struct Node N;
N *start=NULL,*ptr,*tmp;
void CreateNode();
void PrintNode();
void InsertFirst();
void InsertLast();
void InsertAfter();
void DeleteLast();
void DeleteFirst();
void DeleteAfter();
void DeleteBefore();
void InsertBefore();

void CreateNode()
{
 ptr=(N *) malloc (sizeof(N));
 printf("Enter Value:");
 scanf("%d",&ptr->val);
 ptr->next=NULL;
 if(start==NULL)
 {
  start=ptr;
  ptr->prev=NULL;
  tmp=ptr;
 }
 else
 {
  tmp->next=ptr;
  ptr->prev=tmp;
  tmp=ptr;
 }
}
void PrintNode()
{
 ptr=start;
 if(start==NULL)
 {
  printf("Empty List");
  return;
 }
 while(ptr->next!=NULL)
 {
  printf("%d -> ",ptr->val);
  ptr=ptr->next;
 }
 while(ptr!=NULL)
 {
  printf("%d <- ",ptr->val);
  ptr=ptr->prev;
 }
}
void InsertFirst()
{
 ptr=(N *) malloc (sizeof(N));
 printf("Enter Value:");
 scanf("%d",&ptr->val);
 ptr->next=start;
 start->prev=ptr;
 ptr->prev=NULL;
 start=ptr;
}
void InsertLast()
{
 ptr=start;
 while(ptr->next!=NULL)
 {
  ptr=ptr->next;
 }
 tmp=(N *) malloc (sizeof(N));
 printf("Enter Value:");
 scanf("%d",&tmp->val);
 ptr->next=tmp;
 tmp->prev=ptr;
 tmp->next=NULL;
}
void InsertAfter()
{
 int n;
 printf("Enter value after which to insert:");
 scanf("%d",&n);
 ptr=start;
 while(ptr->val!=n)
 {
  ptr=ptr->next;
 }
 tmp=(N *) malloc (sizeof(N));
 printf("Enter value:");
 scanf("%d",&tmp->val);
 tmp->next=ptr->next;
 tmp->next->prev=tmp;
 ptr->next=tmp;
 tmp->prev=ptr;
}
void DeleteLast()
{
 ptr=start;
 while(ptr->next!=NULL)
 {
  ptr=ptr->next;
 }
 ptr->prev->next=NULL;
 free(ptr);
}
void DeleteFirst()
{
 ptr=start;
 start=start->next;
 ptr->next->prev=NULL;
 free(ptr);
}
void DeleteAfter()
{
 int n;
 printf("Enter value after which to delete:");
 scanf("%d",&n);
 ptr=start;
 while(ptr->val!=n)
 {
  ptr=ptr->next;
 }
 tmp=ptr->next;
 ptr->next=tmp->next;
 tmp->next->prev=ptr;
 free(tmp);
 }

void DeleteBefore()
{
 int n;
 printf("Enter value before which to delete:");
 scanf("%d",&n);
 ptr=start;
 while(ptr->val!=n)
 {
  ptr=ptr->next;
 }
 tmp=ptr->prev;
 tmp->prev->next=ptr;
 ptr->prev=tmp->prev;
 free(tmp);
}

void InsertBefore()
{
 int n;
 printf("Enter value before which to insert:");
 scanf("%d",&n);
 ptr=start;
 while(ptr->val!=n)
 {
  ptr=ptr->next;
 }
 tmp=(N *) malloc (sizeof(N));
 printf("Enter value:");
 scanf("%d",&tmp->val);
 tmp->next=ptr;
 tmp->prev=ptr->prev;
 ptr->prev=tmp;
 tmp->prev->next=tmp;
}



int main()
{
 int ch;
 do
 {
   printf("\n -: M E N U :-\n====================");
  printf("\n1......Create Node.");
  printf("\n2......Print Node.");
  printf("\n3......Insert First.");
  printf("\n4......Insert Last.");
  printf("\n5......Insert After.");
  printf("\n6......Delete Last.");
  printf("\n7......Delete First.");
  printf("\n8......Delete After.");
  printf("\n9......Delete Before.");
  printf("\n10.....Insert Before.");
  printf("\n0......Exit.");
  printf("\nEnter Choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:CreateNode();break;
   case 2:PrintNode();break;
   case 3:InsertFirst();break;
   case 4:InsertLast();break;
   case 5:InsertAfter();break;
   case 6:DeleteLast();break;
   case 7:DeleteFirst();break;
   case 8:DeleteAfter();break;
   case 9:DeleteBefore();break;
   case 10:InsertBefore();break;
  }
 }
 while(ch!=0);
 return 0;
}