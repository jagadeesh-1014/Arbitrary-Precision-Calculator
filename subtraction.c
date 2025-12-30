#include "apc.h"
#include<stddef.h>
#include <stdlib.h>

void delete_leading_zeros(Dlist **head, Dlist **tail);

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int data;
	int barrow = 0;

	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1 != NULL && temp2 != NULL)
		{
			data = temp1 ->data - temp2 ->data - barrow;
			if(data < 0)
			{
				data = data +10;
				//insert_first(headR, tailR, data);
				barrow = 1;
			}
			else{
				//insert_first(headR, tailR, data);
				barrow = 0;
			}

			temp1 = temp1 ->prev;
			temp2 = temp2 ->prev;
		}
		else
		{
			data = temp1 ->data - barrow;
			if(data < 0)
			{
				data = data +10;
				//insert_first(headR, tailR, data);
				barrow = 1;
			}
			else{
				//insert_first(headR, tailR, data);
				barrow = 0;
			}
			temp1 = temp1 -> prev;
		}
		insert_first(headR, tailR, data);
	}
	delete_leading_zeros(headR,tailR);
}
void delete_leading_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && (*head != *tail))
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}