# tweet-manager

## Description
The project is desgined to emulate the basic functionalities of Twitter. It makes use of dynamic data structure Linked Lists to store the data for all the tweets. This is a menu-driven program that rely on a user-defined structure allowing the user to run the basic tasks on a set of tweet data.  

## Executing the Program

Compiling the Program-
The program should be compiled as follows
```
make
```

To run the program-
```
./a3
```

To remove all the intermediate .o files:- 
```
make clean
```

## Completed Components

createTweet.c :- the function generates unique userID to all the tweets. 
		If the tweetList is empty, there will be no comparisons of userID (for unique ID), 
		the function will automatically add the tweet to the list.
		the function also checks for edge cases like if the user didn't enter anything in username and tweet text, 
		or if they have entered more than the required number of characters in both.
	
addNodeToList.c :- this function checks if the tweetList is empty or not,
		if not empty, appends the nodes
		else, points that node as head of the tweetList.

deleteTweet.c :- this function deletes the nth tweet the used wants to delete. 
		it takes care if the user wants to delete the first tweet
		also, it prompts user to enter the correct nth tweet

displayTweets.c :- this function displays all the tweets
		displays the correct tweets even after using loadTweetsFromFile function, deleteTweet function, createTweet function, 
		sortID function, etc.

loadTweetsFromFile.c :- this function adds the tweets from a file to the end of the tweetList
			checks for edge case such as if it is not able to open the file

saveTweetsToFile.c :- this function saves all the tweets to a file

searchTweetsByKeyword.c :- this function searches for the keyword and find out where all it has been used in the tweets. 
			even if the keyword is in uppercase letters, it will still be able to find out the tweets containing that keyword

sortID.c :- this function sorts the userIDs using bubble sort algorithm 
	 

## Limitations
- if we call the loadTweetsFromFile function the very first time, all of the tweets are imported, but after this if we try to add tweets using createTweet, it is overwritten.
	-but if called later, everything is appended to the tweetList!
- a specific format of file is used for loadTweetsFromFile (id,user,text,)


## Future Improvements
-memory leaks could be resolved
-a better sorting algorithm could be used