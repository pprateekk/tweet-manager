a3: createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o addNodeToList.o main.o
	gcc -Wall -std=c99 createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o addNodeToList.o main.o -o a3

addNodeToList.o: addNodeToList.c headerA3.h
	gcc -Wall -std=c99 -c addNodeToList.c

sortID.o: sortID.c headerA3.h
	gcc -Wall -std=c99 -c sortID.c

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h
	gcc -Wall -std=c99 -c loadTweetsFromFile.c

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h
	gcc -Wall -std=c99 -c saveTweetsToFile.c

deleteTweet.o: deleteTweet.c headerA3.h
	gcc -Wall -std=c99 -c deleteTweet.c

countStopWords.o: countStopWords.c headerA3.h
	gcc -Wall -std=c99 -c countStopWords.c

searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h
	gcc -Wall -std=c99 -c searchTweetsByKeyword.c

displayTweets.o: displayTweets.c headerA3.h
	gcc -Wall -std=c99 -c displayTweets.c

createTweet.o: createTweet.c headerA3.h
	gcc -Wall -std=c99 -c createTweet.c

main.o: main.c headerA3.h
	gcc -Wall -std=c99 -c main.c

clean: 
	rm *.o a3
