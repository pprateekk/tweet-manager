#include "headerA3.h"

void displayTweets(tweet * tweetList)
{
	tweet * pointer;
	tweet * head;
	pointer = NULL;
	head = tweetList;			//the head of the tweetList
	pointer = head;				//initialising the pointer to the head of the linked list

	/*
		If the linked list is empty, a message will be displayed to enter some data;
		Else -
		The pointer will traverse through the linked list, 
		and print all of the elements/data.
	*/
	if (pointer == NULL)
	{
		printf("Please enter some data.\n");
	}
	else
	{
		while (pointer != NULL)
		{
			printf("%d: Created by %s: %s\n", pointer->id, pointer->user, pointer->text);
			pointer = pointer->next;
		}
	}
}
