#include "headerA3.h"

int main()
{
	int userChoice;							//user input for the menu
	userChoice = 0; 

	int countNumberOfTimesLooped;			//used for function - 1
	tweet * tweetList; 						//this is the tweetList
	tweet * pointerToTweetList;				//this is the pointer to the tweetList
	countNumberOfTimesLooped = 0;
	tweetList = NULL;
	pointerToTweetList = NULL;
	tweet ** head = NULL; 

	// int searchTweet = 0; 						//Function -3: commented because it displays a warning that it was not used in the porgram, even though it was used.

	while(1)
	{
		printf("1. Create a new tweet\n");
		printf("2. Display tweets\n");
		printf("3. Search a tweet (by keyword)\n");
		printf("4. Find how many words are \"stop words\"\n");
		printf("5. Delete the nth tweet\n");
		printf("6. Save tweets to a file\n");
		printf("7. Load tweets from a file\n");
		printf("8. Sort the given linked list on userid\n");
		printf("9. Exit\n");
		printf("Choose a menu option: ");
		scanf("%d", &userChoice);

		if (userChoice == 1)
		{
			countNumberOfTimesLooped += 1;
			// printf("%d: \n", countNumberOfTimesLooped);
			/*
				Initially, the tweetList is NULL; so the first set of data is pointed to it (beginning) (if part);
				then, the pointer to tweetList is returned (pointerToTweetList);
				and the next set of data will be added to the end of that list.
			*/


			if (countNumberOfTimesLooped == 1)			//because tweetList is NULL initially
			{
				pointerToTweetList = createTweet (tweetList);
			}
			else
			{
				pointerToTweetList = createTweet(pointerToTweetList);
			}
		}
		else if (userChoice == 2)
		{
			displayTweets(pointerToTweetList);
		}
		else if (userChoice == 3)
		{
			// searchTweet = searchTweetsByKeyword(pointerToTweetList);
			searchTweetsByKeyword(pointerToTweetList);
		}
		else if (userChoice == 4)
		{
			countStopWords(pointerToTweetList);
		}
		else if (userChoice == 5)
		{
			deleteTweet(&pointerToTweetList);
		}
		else if (userChoice == 6)
		{
			saveTweetsToFile(pointerToTweetList);
		}
		else if (userChoice == 7)
		{
			loadTweetsFromFile(&pointerToTweetList);
		}
		else if (userChoice == 8)
		{
			head = &pointerToTweetList;
			sortID (head);
		}
		else if (userChoice == 9)
		{
			exit(0);
		}
		else
		{
			printf("Please enter a valid choice number (1-9) \n\n");
		}
	}

	return 0;
}
