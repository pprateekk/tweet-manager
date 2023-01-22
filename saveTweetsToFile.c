#include "headerA3.h"

void saveTweetsToFile(tweet * tweetList)
{
	char nameOfFile[25];
	FILE * filePointer = NULL;
	tweet * pointer; 	//to traverse through the linked list
	pointer = NULL;
	printf("Enter the filename where you would like to store your tweets: ");
	scanf("%s", nameOfFile);
	filePointer = fopen(nameOfFile, "w");	//opening the file in writing mode 

	if (filePointer == NULL)
	{
		printf("Error: Unable to open the file!\n");
	}
	else
	{
		/*
			this loop will save all the tweets to the file
		*/
		for (pointer = tweetList; pointer != NULL; pointer = pointer->next)
		{
			fprintf(filePointer, "%d,%s,%s,\n", pointer->id, pointer->user, pointer->text);
		}
		printf("Output successful!\n");
	}

	fclose(filePointer);
}
