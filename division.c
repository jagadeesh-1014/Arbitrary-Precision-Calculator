#include "apc.h"
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>


int compare_len(Dlist **head, Dlist **tail);
int compare_value(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);


int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int count =0;

	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int len1,len2;
	len1 = compare_len(head1,tail1);
	len2 = compare_len(head2,tail2);
	
	int val;
		int safety = 0;
	while((len1 > len2 || len1 == len2) && safety<1000)
	{
		safety++;
		if(len1 == len2)
		{
			 val = compare_value(head1,tail1,head2,tail2);

			 if(val == 1)
			 {
				subtraction(head1,tail1,head2,tail2,headR,tailR);
				
				count++;
				delete_list(head1,tail1);

				*head1 = *headR;
				*tail1 = *tailR;
				*headR = *tailR = NULL;


				len1 = compare_len(head1,tail1);
				len2 = compare_len(head2,tail2);
				
			}
			else{
				break;
			}
		}
		else
		{
		subtraction(head1,tail1,head2,tail2,headR,tailR);
		count++;
		delete_list(head1,tail1);

		*head1 = *headR;
		*tail1 = *tailR;
		*headR = *tailR = NULL;

		len1 = compare_len(head1,tail1);
		len2 = compare_len(head2,tail2);
		}

	}
	return count;
}
int compare_len(Dlist **head, Dlist **tail)
{
	int count =0;
	if(*head == NULL)
	{
		return 0;
	}
	Dlist *temp = *head;
	 while(temp != NULL)
	 {
		count++;
		temp = temp -> next;
	 }
	 return count;
}
int compare_value(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
	Dlist *temp1 = *head1;
	Dlist *temp2 = *head2;

	while(temp1 != NULL && temp2 != NULL)
	{
		int data1 = temp1 -> data;
		int data2 = temp2 -> data;
		if(data1 > data2)
		{
			return 1;
			break;
		}
		else if(data1 < data2)
		{
			return 2;
			break;
		}

			temp1 = temp1 -> next;
			temp2 = temp2 -> next;
		

	}
	return 1;
}
