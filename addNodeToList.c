#include "headerA3.h"

void addNodeToList(tweet ** tweetList, tweet * node)
{
	tweet * head; 					//head of the tweetList
	head = *tweetList;

	/*
		The following loop will see if the tweetList is empty or not and then add the node accordingly.
		If the user is enetering the data for the first time (tweetList is NULL/empty), the tweetList will point to that node (beginning).
		Else, the other nodes will be added to the end of the list.
	*/
	if (head == NULL)
	{
		*tweetList = node;
		head = *tweetList;
	}
	else
	{
		while ((*tweetList)->next != NULL)
		{
			(*tweetList) = (*tweetList)->next;
		}
		(*tweetList)->next = node;
		*tweetList = head;					//pointing to the head of the tweetList, since we used it(tweetList) to traverse through the list to find the end.				
	}
}
