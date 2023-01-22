#include "headerA3.h"

int searchTweetsByKeyword(tweet * tweetList)
{
	char keyWord[25]; 			//to store the keyword entered by the user
	int i;
	int lenOfKeyword;			//for the length of the keyword entered
	tweet * pointer; 			//to traverse through the list
	int returnValue;			//the value which will be returned
	int lenOfText;				//length of the tweet text
	i = 0; 
	lenOfKeyword = 0; 
	pointer = NULL;
	returnValue = 0;
	lenOfText = 0;

	printf("Enter a keyword to search: ");
	scanf("%s", keyWord);

	lenOfKeyword = strlen(keyWord);
	char lowerCaseKeyword[lenOfKeyword];		//this is used to get the lowercased characters of the entered keyword
	strcpy(lowerCaseKeyword, keyWord);

	/*
		the following loop converts all the upper case letters of keyword to lowercase. 
	*/
	for (i = 0; i < lenOfKeyword; i++)
	{
		if (lowerCaseKeyword[i] >= 'A' && lowerCaseKeyword[i] <= 'Z')
		{
			lowerCaseKeyword[i] = lowerCaseKeyword[i] + 32;
		}
	}

	/*
		this loop iterates through the tweetList
	*/
	for (pointer = tweetList; pointer != NULL; pointer = pointer->next)
	{
		lenOfText = strlen(pointer->text);
		char lowerCaseText[lenOfText];						//to store the lowercase converted text
		strcpy(lowerCaseText, pointer->text);
		for (i = 0; i < lenOfText; i++)
		{
			if (lowerCaseText[i] >= 'A' && lowerCaseText[i] <= 'Z')
			{
				lowerCaseText[i] = lowerCaseText[i] + 32; 	//converting to lowercase character
			}
		}
		
		/*
			this loop compares the lowercased letters of the keyword and lowercased letters of the text; (lowercased because the search is case-insensitive)
			and finds that specific text.
		*/
		if ( strstr(lowerCaseText, lowerCaseKeyword) != NULL)
		{
			printf("Match found for '%s': %s wrote: \"%s\"\n", keyWord, pointer->user, pointer->text);
			returnValue = 1;
		}
	}
	
	return returnValue;
}
