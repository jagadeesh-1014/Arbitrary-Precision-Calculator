#include "apc.h"
//#include "main.c"
#include<stddef.h>
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int data ;
	int carry = 0;
	
	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1 != NULL && temp2 != NULL)
		{
			data = temp1 ->data + temp2 ->data + carry;
			
			if(data > 9)
			{
				data = data % 10;
				//insert_first(headR, tailR, data);
				carry = 1;
				
			}
			else{
				//insert_first(headR, tailR, data);
				carry = 0;
			}
			temp1 = temp1 ->prev;
			temp2 = temp2 ->prev;

		}
		else if(temp1 != NULL && temp2 == NULL)
		{
			data = temp1 ->data + carry;

			if(data > 9)
			{
				data = data % 10;
				//insert_first(headR, tailR, data);
				carry = 1;
				
			}
			else{
				//insert_first(headR, tailR, data);
				carry = 0;
			}
			temp1 = temp1 ->prev;

		}
		else if(temp1 == NULL && temp2 != NULL)
		{
			data = temp2 ->data + carry;

			if(data > 9)
			{
				data = data % 10;
				//insert_first(headR, tailR, data);
				carry = 1;
				
			}
			else{
				//insert_first(headR, tailR, data);
				carry = 0;
			}
			temp2 = temp2 ->prev;

		}
		insert_first(headR, tailR, data);


		
	}
	if(carry == 1)
	{
		data = 1;
		insert_first(headR, tailR, data);
	}


}
