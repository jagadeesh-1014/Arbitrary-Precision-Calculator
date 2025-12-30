/*
Started Date  : 23-Sep-2025
Completed Date: 30-Sep-2025
Student Name  : jagadeesh
Project Name  : APC (Arbitrary Precision Calculator)
Description   : Designing Calculator to perform the basic arithmetic operations are
				1. Addition
					--> to add two large inputs
					--> eg: 10000000000000000000000000000000 + 945112111554215822512121212121 = 10945112111554215822512121212121
				2. Subtraction
					--> to subtract two large inputs 
					--> eg: 9551644545464999218123311611211 - 215441215455121212154512129446 = 9336203330009878005968799481765
				3. Multiplication
					--> to multiply two large inputs
					--> eg: 866166464646646464646464466465 x 51616116164644646464646462321 = 44708148857120874281461614728956002287070106693194990565265
				4. Division
					--> to divide two large inputs
					--> eg: 6646494949496494949 / 1616161646464164 = 4112
 */

#include "apc.h"
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>


void print_list(Dlist *head);
//int compare(char *argv[]);


int main(int argc , char * argv[])
{
	int i = 0;
	if(argc != 4)
	{
		printf("Enter min 4 arguments : \n");
		printf("pass aruguments like :\n");
		printf("			./a.out <operand1> <operator> <operand2>\n");

		return FAILURE;
	}

	 // Check both operands contain only digits
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)argv[1][i]))
        {
            printf("Enter digits only for operand 1\n");
            return FAILURE;
        }
    }

    for (int i = 0; argv[3][i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)argv[3][i]))
        {
            printf("Enter digits only for operand 2\n");
            return FAILURE;
        }
	}
	printf("--------------------Arbitrary Precision Calculator---------------------\n");

	/* Declare the pointers */
      
	Dlist *head1 = NULL, *tail1=NULL;
    Dlist *head2 = NULL, *tail2=NULL; 
    Dlist *headR = NULL,*tailR=NULL;


	digit_to_list(&head1,&tail1,&head2,&tail2,argv);
	//print_list(head1);
	//print_list(head2);

	char operator=argv[2][0];


		switch (operator)
		{
			case '+':
                               // digit_to_list(&head1,&tail1,&head2,&tail2,argv);
				/* call the function to perform the addition operation */
                                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
							
								print_list(head1);
								printf("+ ");
								print_list(head2);
								printf("= ");
								print_list(headR);
								printf("\n");
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				int ret = compare(argv);
				printf("ret val is %d\n",ret);
				if (ret == 1)
				{
					subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
					print_list(head1);
					printf("- ");
					print_list(head2);
					printf("= ");
					print_list(headR);
					printf("\n");
				}
				else
				{
					subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
					
					print_list(head1);
					printf(" - ");
					print_list(head2);
					printf(" = ");
					printf(" - ");
					print_list(headR);
					printf("\n");
				}

				break;
			case 'x':	
				/* call the function to perform the multiplication operation */
				multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				print_list(head1);
				printf("  x   ");
				print_list(head2);
				printf(" =  ");
				print_list(headR);
				printf("\n");
				break;
			case '/':	
				/* call the function to perform the division operation */

				int ret2 = compare(argv);
				if(ret2 == 1)
				{
					print_list(head1);
				int ret5 = division(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				
				printf(" / ");
				print_list(head2);
				printf(" = ");
				printf(" %d \n",ret5);
				//printf("ret is %d",ret5);
				//print_list(headR);
				}
				else if(ret2 == 2)
				{
					print_list(head1);
					printf(" / ");
					print_list(head2);
					printf(" = ");
					printf(" 0 ");
					printf("\n");
					//printf("result is 0\n");
				}
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
		printf("--------------------------------------------------------------------------\n");
	return 0;
}

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
    int data;
	int i;

    char *str1 = argv[1];
    for (i = 0; str1[i] != '\0'; i++)
    {
        data = str1[i] - '0';
        insert_last(head1, tail1, data);
    }

    char *str2 = argv[3];
    for (i = 0; str2[i] != '\0'; i++)
    {
        data = str2[i] - '0';
        insert_last(head2, tail2, data);
    }
}

/*COMPARE FUNCTION*/
int compare(char *argv[])
{
	char * str1 = argv[1];
	char *str2 =  argv[3];

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if(len1 > len2)
	{
		return 1;
	}
	else if (len1 < len2)
	{
		return 2;
	}
	else if(len1 == len2)
	{
		int i = 0;
		while(str1[i] != '\0' && str2[i] != '\0')
		{
			if(str1[i] > str2[i])
			{
				return 1;
			}
			else if(str1[i] < str2[i])
			{
				return 2;
			}
			else{
				i++;
			}
		}
		return 1;
	}
	return 0;
}
