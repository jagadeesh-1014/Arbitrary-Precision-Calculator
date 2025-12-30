#include "apc.h"
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

/*INSERT FIRST...*/
int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new -> prev = NULL;
    new -> next = NULL;
    new -> data = data;
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        new -> next = *head;
        (*head)->prev = new; 
        *head = new;
        return SUCCESS;
        
    }
}

int insert_last(Dlist **head, Dlist **tail, int data)
{
    
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new -> prev = NULL;
    new -> next = NULL;
    new -> data = data;
    if(*tail == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        new -> prev = *tail;
        (*tail) -> next = new;
        *tail = new;
        return SUCCESS;
        
    }
}

/*DELETE LIST*/
int delete_list(Dlist **head, Dlist **tail)
{
  if (*head == NULL)
  {
      return FAILURE;
  }
  
   Dlist * temp ;
  if(*head == *tail)
  {
      free(*head);
      *head = NULL;
      *tail = NULL;
      return SUCCESS;
  }
 else
    {
        while(temp != NULL)
        {
        temp -> next -> prev =NULL;
        *head = temp -> next;
        free(temp);
        temp = *head;
       
        }
    }
}

/*.-----PRINT LIST--------*/
void print_list(Dlist *head)
{
	// Cheking the list is empty or not 
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    //printf("Head -> ");
	    while (head)		
	    {
		   // Printing the list 
		    printf("%d ", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
        //printf("\n");
    	//printf("<- Tail\n");
    }
}