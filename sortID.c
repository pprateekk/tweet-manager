#include "headerA3.h"

void sortID (tweet ** head)
{
	tweet * headPointer;				// marks the head 
	tweet * j; 							// to point to the next pointer
	tweet * temp;						// to store data temporary (swap)
	temp = malloc(sizeof(tweet));		// allocating memory to store the data

	headPointer = *head;				// pointing to the head

	/*
		using bubble sort alogrithm
	*/
	for (*head = headPointer; *head != NULL; *head = (*head)->next)	
	{
		for (j = (*head)->next; j != NULL; j = j->next)
		{
			if ((*head)->id > j->id)					//if the userId of the current tweet is grater than the userID of the next pointer -> SWAP
			{
				// storing data in temp
				temp->id = (*head)->id;
				strcpy(temp->user, (*head)->user);
				strcpy(temp->text, (*head)->text);
				// changing the elements of current tweet node
				(*head)->id = j->id;
				strcpy((*head)->user, j->user);
				strcpy((*head)->text, j->text);
				// changing the elements of the next tweet node
				j->id = temp->id;
				strcpy(j->user, temp->user);
				strcpy(j->text, temp->text);
			}
		}
	}

	printf("The tweetList is sorted!\n");

	*head = headPointer;	// setting the pointer to the head, previously was null	
}
