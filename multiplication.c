#include "apc.h"
#include<stddef.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *headR1 = NULL;
	Dlist * tailR1 = NULL;
	Dlist *headR2 = NULL;
	Dlist * tailR2 = NULL;
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int count = 0;
	int carry = 0;
	int data;

	while(temp2 != NULL)
	{
		headR2 = NULL;
        tailR2 = NULL;
        carry = 0;
        temp1 = *tail1;

		while(temp1 != NULL)
		{
			int val1 = temp1 ->data;
			int val2 = temp2 -> data;

			data = val1 * val2 + carry;
			
			if(data > 9)
			{
				carry = data/10;
				data = data %10;
				
			}
			else{
				carry = 0;
			}
			insert_first(&headR2, &tailR2, data);
			temp1 = temp1 ->prev;

		}
		if (carry != 0)
        {
            insert_first(&headR2, &tailR2, carry);
        }
		for (int i = 0; i < count; i++)
        {
            insert_last(&headR2, &tailR2, 0);  // shift partial result by count zeros
        }

		count++;

		if (count == 0)
        {
            headR1 = headR2;
            tailR1 = tailR2;
        }
        else
		{
			addition(&headR1,&tailR1,&headR2,&tailR2,headR,tailR);
			delete_list(&headR2,&tailR2);
			headR1 = *headR;
			tailR1 = *tailR;

			*headR = NULL;
			*tailR = NULL;
		}
		temp2 = temp2 ->prev;
	}
	*headR = headR1;
    *tailR = tailR1;
	return SUCCESS;

}
