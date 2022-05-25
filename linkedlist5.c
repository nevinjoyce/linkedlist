/* Singly Linked List: Append, Display, Delete, Traverse */
#include <stdio.h>
#include <stdlib.h>
void main()
{	
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL, *pos=NULL, *tail=NULL;
	int ch, entry;
	while(1)
	{
		printf("\n1. Append\n2. Display\n3. Delete\n4. Search for an Element(Traverse)\n5. Insert Element at Given Position\n6. Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("\nEnter Data: ");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->data=entry;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail=tail->next;
					tail->data=entry;
				} break;
			}
			case 2:
			{
				pos=head;
				printf("\nElements are: ");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				} break;
			}
			case 3:
			{
				int num;
				pos=head;
				printf("\nEnter Position of Data:");
				scanf("%d",&entry);
				if(entry==0)
				{
					num=pos->data;
					head=head->next;
					pos->next=NULL;
					free(pos);
				}
				else
				{
					for(int i=0;i<entry-1;i++)
					{	
						pos=pos->next;
					}
					num=pos->next->data;
					struct node*del=pos->next;
					pos->next=pos->next->next;
					del->next=NULL;
					free(del);
				}
				printf("\nNode Deleted is %d\n",num);
				break;
			}
					
			case 4:
			{	
				int num,flag=0,count=-1;
				printf("\nEnter Which Element to Search for: ");
				scanf("%d", &num);			
				pos=head;
				while(pos!=NULL)
				{
					count++;
					if(pos->data==num)
					{
						printf("\nElement is present at position %d\n",count);
						flag=1;
					}
					pos=pos->next;

				} 
				if(flag==0)
				{
					printf("\nElement not found in linked list\n");
				} break;
			}
			case 5:
			{
				struct node *temp;
				int i, keydata;
				printf("\nEnter Position: ");
				scanf("%d",&entry);
				printf("\nEnter Data: ");
				scanf("%d",&keydata);
				temp=head;
				if(entry==0)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->data=keydata;
					head->next=temp;
				}
				else
				{
					struct node*temp2;
					for(i=0;i<entry-1;i++)
					{	temp=temp->next;
					}
					temp2=(struct node*)malloc(sizeof(struct node));
					temp2->data=keydata;
					temp2->next=temp->next;
					temp->next=temp2;
				}break;
			}
			case 6:
			{
				printf("\nGood Bye\n");
				exit(0);
			}
		}
	}
}
