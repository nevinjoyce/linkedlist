/* Singly Linked List random insertion, with time tracking */
/* Singly Linked List v1.3 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
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
		printf("\n1.  Random Element Insert\n2. Display\n3. Count\n4. Search for an Element\n5. Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				struct timeval t0;
   				struct timeval t1;
  				 float elapsed;
   				long num, j;
				printf("Enter how many elements to be generated: ");
				scanf("%ld",&num);
   				gettimeofday(&t0, NULL);
   				 for(j = 0; j < num; j++)
        			{
        				if(head==NULL)
					{
						head=(struct node*)malloc(sizeof(struct node));
						head->data=rand()%100;
						pos=head;
						tail=head;
					}
					else
					{
						tail->next=(struct node*)malloc(sizeof(struct node));
						tail=tail->next;
						tail->data=rand()%100;
					}
    				}
   				gettimeofday(&t1, NULL);

   				elapsed = timedifference_msec(t0, t1);

   				printf("Code executed in %f milliseconds.\n", elapsed);
				break;
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
