#include "headerA3.h"

tweet * createTweet(tweet * tweetList)
{
	tweet * newNode; 									//this will be added to the end of the linked list
	newNode = malloc(sizeof(tweet));

	int userNameLength;									//used to check if the user entered the correct length for the username
	int userTextLength;									//used to check if the user entered the correct length of tweet text
	int aNumberForUsername;								//will be set to 1 once the user enters the correct number of characters for username								
	int aNumberForText;									//will be set to 1, once the user enters the correct no of chars for text
	aNumberForText = 0;									
	userNameLength = 0;
	userTextLength = 0;
	aNumberForUsername = 0;

	printf("Enter a username: "); 
	getchar();
	fgets(newNode->user, 100, stdin);	//51
	newNode->user[strlen(newNode->user) - 1] = '\0';	//removing \n from the string
	userNameLength = strlen(newNode->user);

	/*
		the following loop checks if the user entered an empty string(username) or a string with more no. of chars than specified;
		if so, ask the user to enter the correct username.
	*/
	while (aNumberForUsername == 0)
	{
		if (userNameLength == 0)
		{
			printf("Username can not be empty. Please enter again.\n");
			printf("Enter a username: ");
			fgets(newNode->user, 100, stdin);	
			newNode->user[strlen(newNode->user) - 1] = '\0';	//removing \n from the string
			userNameLength = strlen(newNode->user);
		}
		else if (userNameLength > 51)
		{
			printf("Please enter only 51 characters for username\n");
			printf("Enter a username: ");
			fgets(newNode->user, 100, stdin);
			newNode->user[strlen(newNode->user) - 1] = '\0';	//removing \n from the string
			userNameLength = strlen(newNode->user);
		}
		else
		{
			aNumberForUsername = 1;
		}
	}

	printf("Enter the user's tweet: ");
	fgets(newNode->text, 200, stdin);
	newNode->text[strlen(newNode->text) - 1] = '\0';	//removing \n from the string
	userTextLength = strlen(newNode->text);

	/*
		the following loop checks if the user entered an empty string(text) or a string with more no. of chars than specified;
		if so, ask the user to enter the correct no. of chars for text.
	*/
	while (aNumberForText == 0)
	{
		if (userTextLength == 0)
		{
			printf("Tweet text can not be empty. Please enter again.\n");
			printf("Enter the user's tweet: ");
			fgets(newNode->text, 200, stdin);
			newNode->text[strlen(newNode->text) - 1] = '\0';	//removing \n from the string
			userTextLength = strlen(newNode->text);
		}
		else if (userTextLength > 141)
		{
			printf("Please enter only 141 characters for tweet text\n");
			printf("Enter the user's tweet: ");
			fgets(newNode->text, 200, stdin);
			newNode->text[strlen(newNode->text) - 1] = '\0';	//removing \n from the string
			userTextLength = strlen(newNode->text);
		}
		else
		{
			aNumberForText = 1;
		}
	}
	
	newNode->next = NULL; 								//to mark the end of this node

	/*
		Following commands are used to generate a unique userID
	*/
	int sumOfCharsInUser; 								//to find the sum of ASCII value of characters in the username
	int lenOfText; 										//length of the user's tweet
	int lenOfUser;										//length of the user's name
	int initialUserId; 									//sum of sumOfCharachtersInUser + lenOfText;	
	int newUserId; 										//if same userIds are found, a new user ID will be calculated
	int i; 
	sumOfCharsInUser = 0;
	lenOfText = 0;
	lenOfUser = 0;
	initialUserId = 0;
	newUserId = 0;

	lenOfText = strlen(newNode->text);
	lenOfUser = strlen(newNode->user);

	/*
		Calculating sum of ascii values of characters of user's name
	*/
	for (i = 0; i < lenOfUser; i++)
	{
		sumOfCharsInUser = sumOfCharsInUser + newNode->user[i] ;
	}

	initialUserId = sumOfCharsInUser + lenOfText;

	tweet * pointer; 		//pointer to traverse through the linked list
	int randomNumber = 0; 	//to store the random number generated b/w 1 and 999. 

	/*
		When the tweetList is empty, there will be no comparison of userIds
		so, userID = initialUserID (calculated above).
		Else part: tweetList is populated with something, 
				the pointer will traverse through the linked list to find if there exist a same userID. 
				if exist:- newUser ID generated. 
				else:- initialUserID which was calculated before will be used. 
	*/
	if (tweetList == NULL)
	{
		newNode->id = initialUserId;
		printf("\nYour computer-generated userid is %d.\n", newNode->id);
	}
	else
	{
		for (pointer = tweetList; pointer != NULL; pointer= pointer->next)
		{
			if (pointer->id == initialUserId)
			{
				randomNumber = rand() % 998 + 1; 
				newUserId = initialUserId + randomNumber;
				newNode->id = newUserId;
				break;	//if even one of the same userid is enocuntered, it will be changed, thus a break is used. 
			}
			else
			{
				newNode->id = initialUserId;
			}
		}
		printf("\nYour computer-generated userid is %d.\n", newNode->id);
	}

	addNodeToList(&tweetList, newNode);					//to add the node to the end of the list

	return tweetList;
}
