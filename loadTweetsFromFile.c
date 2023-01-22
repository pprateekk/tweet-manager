#include "headerA3.h"

void loadTweetsFromFile(tweet ** tweetList)
{
	char fileName[25]; 
	FILE * filePointer = NULL;
	tweet * newNode; 									//this will be added to the end of the linked list
	
	printf("Enter a filename to load from: ");
	scanf("%s", fileName);

	filePointer = fopen(fileName, "r");					//opening in read mode

	char * aSingleWord;									//to point to a single word in the tweet
	char userNameCopy[51];
	char userTextCopy[141];
	int countNumberOfLines = 0;
	int count = 0; 										//for the last case
	char aString[250];									//to store the copy of tweet
	char forNumberOfLines[250];

	if (filePointer == NULL)
	{
		printf("Error: Couldn't open the file.\n");
	}
	else
	{
		while (!(feof(filePointer)))
		{
			fgets(forNumberOfLines, 250, filePointer);
			countNumberOfLines += 1;

		}
		fseek(filePointer, 0, SEEK_SET);	//pointing to the start of the file

		while (fgets(aString, 250, filePointer) != NULL)
		{
			newNode = malloc(sizeof(tweet));	//allocating memory to it
			count += 1;
			aString[strlen(aString) - 1] = '\0';

			aSingleWord = strtok(aString, ",");		//userID
			int userIdCopy = atoi(aSingleWord);

			aSingleWord = strtok(NULL, ",");		//userName
			strcpy(userNameCopy, aSingleWord);

			/*
				following loop is for user's tweet text
			*/
			if (count < countNumberOfLines)
			{
				aSingleWord = strtok(NULL, "\n");
				aSingleWord[strlen(aSingleWord) - 1] = '\0';
				strcpy(userTextCopy, aSingleWord);
				userTextCopy[strlen(aSingleWord) - 1] = '\0';
			}
			else if (count == countNumberOfLines)
			{
				aSingleWord = strtok(NULL, "\0");
				strcpy(userTextCopy, aSingleWord);
			}

			/*
				copying all the data to a newNode
			*/
			newNode->id = userIdCopy;
			strcpy(newNode->user, userNameCopy);
			strcpy(newNode->text, userTextCopy);
			newNode->next = NULL;
			
			
			addNodeToList (tweetList, newNode); //inserting to the end of the linked list
			
		}
		printf("Tweets imported!\n");
	}
}
