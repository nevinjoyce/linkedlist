/* Singly Linked List v1.2 */
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
	int ch, entry, count;
	while(1)
	{
		printf("\n1. Insert\n2. Display\n3. Count\n4. Search for an Element\n5. Exit\nEnter Your Choice: ");
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
				pos=head;
				count=0;
				while(pos!=NULL)
				{
					count++;
					pos=pos->next;
				} 
				printf("\n Number of Elements is: %d\n",count);
				break;
			}
			case 4:
			{	
				int num,flag=0;
				printf("\nEnter Which Element to Search for: ");
				scanf("%d", &num);			
				pos=head;
				count=0;
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
				printf("\nGood Bye\n");
				exit(0);
			}
		}
	}
}
