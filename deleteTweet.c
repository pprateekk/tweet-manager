#include "headerA3.h"

void deleteTweet(tweet ** tweetList)
{
	tweet * pointer; 			//this is a pointer to traverse through the linked list
	pointer = NULL;

	int nthTweet = 0;			//nth tweet user wants to delete

	int countTweets = 0;		//total number of tweets in the linked list

	//this loop counts the total number of tweets in the tweetList
	for (pointer = *tweetList; pointer != NULL; pointer = pointer->next)
	{
		countTweets += 1;
	}
	printf("Currently there are %d tweets.\n\n", countTweets);
	printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", countTweets);
	scanf("%d", &nthTweet);

	int correctInput = 0;		//to check if the user has entered the correct input

	//the following loop asks the user to enter the nth tweet repeatedly until its correct
	while (correctInput == 0)
	{
		if (nthTweet > countTweets)
		{
			printf("Please enter the correct nth tweet you want to delete!\n\n");
			printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", countTweets);
			scanf("%d", &nthTweet);
		}
		else
		{
			correctInput = 1;
		}
	}

	int oneMoreCount = 0; 
	tweet * head; 				//to point to the head of the tweetList
	head = *tweetList;
	tweet * temp;				//the node/tweet the user wants to delete
	temp = head;
	int countBefore = 0;		//used to find the previous node of the node to be deleted
	int userIDTweetDel = 0; 	//stores the userId of the tweet which was deleted


	/*
		The following loop checks if the user want to delete the first tweet or any other from the tweetList
	*/
	if (nthTweet == 1)
	{
		for (*tweetList = head; *tweetList != NULL; *tweetList = (*tweetList)->next)
		{
			head = *tweetList;							//assigning the head of the tweetlist
			if (head->next != NULL)						//to check for the edge case, if only 1 tweet is present
			{
				head = head->next;						//since we will be deleting the first node, the head would be the next node. 
				userIDTweetDel = (*tweetList)->id;
				(*tweetList)->next = NULL;				//pointing the tweetlist (previous head) to NULL to delink from the linked list
				free(*tweetList);			
			}
			else	//if the next head in null, there is nothing in the tweetlist.
			{
				head = NULL;
				printf("No more tweetusers left\n");
			}
			printf("Tweet %d deleted. There are now %d tweets left.\n", userIDTweetDel, countTweets - 1);
		}
		*tweetList = head; 								//pointing to the new linked list
	}
	else
	{
		for (*tweetList = head; *tweetList != NULL; *tweetList = (*tweetList)->next)
		{
			countBefore = 1;
			oneMoreCount += 1;

			if ((oneMoreCount + countBefore) == nthTweet)	//this condition finds the previous node/tweet of the tweet to be deleted
			{
				if ((*tweetList)->next->next != NULL)		//checking for the edge case, if the last tweet is to be deleted from the tweetList
				{
					temp = (*tweetList)->next;				//tweet to be deleted
					userIDTweetDel = temp->id;
					(*tweetList)->next = temp->next;		//pointing the previous tweet to the next of the tweet to be deleted
					temp->next = NULL;						//setting the next pointer of the tweet to be deleted to null
					free(temp);
					printf("Tweet %d deleted. There are now %d tweets left.\n", userIDTweetDel, countTweets - 1);
				}
				else
				{
					temp = (*tweetList)->next;
					userIDTweetDel = temp->id;
					(*tweetList)->next = NULL;				//pointing the next to null, becuase the tweet to be deleted was last, so after deleting this one will be last
					temp->next = NULL;
					free(temp);
					printf("Tweet %d deleted. There are now %d tweets left.\n", userIDTweetDel, countTweets - 1);
				}
				
			}
		}
	}
	*tweetList = head;		//setting the pointer tweetList to the head of the tweetList
}
