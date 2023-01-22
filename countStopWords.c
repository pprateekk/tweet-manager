#include "headerA3.h"

void countStopWords(tweet * tweetList)
{
	char stopWordsArr[25][5] = {"a", "an", "and", "are", "as", "at", "be", "by", "for", "from", "has", "he", "in", "is", "it", "its", "of", "on", "that", "the", "to", "was", "were", "will", "with"};

	int countStopWord = 0;
	int countTweet = 0;
	tweet * pointer; 
	pointer = NULL; 
	int countWords = 0;
	
	char * singleWord = NULL;
	char ** words; 				//to store the individual word from the string
	words = malloc (sizeof(char*) * 2);

	int lengthOfText = 0;

	int i = 0; 

	for (pointer = tweetList; pointer != NULL; pointer = pointer->next)
	{
		lengthOfText = strlen(pointer->text);
		char copyOfTweetText [lengthOfText];
		strcpy(copyOfTweetText, pointer->text);				//copying the tweet text to this array
		singleWord = strtok (copyOfTweetText, " ");
		words[i] = malloc((sizeof(char) * strlen(singleWord)) * 2);
		strcpy(words[i], singleWord);

		i = i+1;	//incrementing to +1 so that the next word is stored in the next index
		while (singleWord != NULL)
		{
			countWords += 1;
			singleWord = strtok (NULL, " ");
			if (singleWord != NULL)
			{
				words[i] = malloc((sizeof(char) * strlen(singleWord)) * 2);
				strcpy(words[i], singleWord);
				words = realloc (words, sizeof(char*) * (i+3));
			}
			i++;
		}
		countTweet += 1;
		i = i - 1;
	}

	

	for (i = 0; i < countWords; i++)
	{
		for (int j = 0; j < strlen(words[i]); j++)
		{
			if (words[i][j] >= 'A' && words[i][j] <= 'Z')
			{
				words[i][j] = words[i][j] + 32; 	//converting to lowercase character
			}
		}
	}

	/*
		this loop compares the stopwords with the words in the text(in words array);
		if equal, count of stopwords is incremented to 1
	*/
	for (i = 0; i < 25; i++)
	{
		for (int j = 0; j < countWords; j++)
		{
			if (strcmp(stopWordsArr[i], words[j]) == 0)
			{
				countStopWord += 1;
			}
		}
	}
	
	printf("Across %d tweets, %d stop words were found.\n", countTweet, countStopWord);
}
