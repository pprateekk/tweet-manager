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
<pre>
createTweet.c :- The function generates unique userID to all the tweets. 
		If the tweetList is empty, there will be no comparisons of userID (for unique ID);
		the function will automatically add the tweet to the list.  
		The function also checks for edge cases for eg. if the user didn't enter anything in username and tweet text,   
		or if they have entered more than the required number of characters in both.
	
addNodeToList.c :- This function checks if the tweetList is empty or not,
		if not empty, appends the nodes
		else, points that node as head of the tweetList.

deleteTweet.c :- This function deletes the nth tweet the used wants to delete. 
		it takes care if the user wants to delete the first tweet
		also, it prompts user to enter the correct nth tweet

displayTweets.c :- This function displays all the tweets.
		Displays the correct tweets after the modification of the list.

loadTweetsFromFile.c :- This function adds the tweets from a file to the end of the tweetList;
			checks for edge case such as if it is not able to open the file

saveTweetsToFile.c :- This function saves all the tweets to a file

searchTweetsByKeyword.c :- This function searches for the keyword and find out where all it has been used in the tweets. 
			Even if the keyword is in uppercase letters, it will still be able to find out the tweets containing that keyword

sortID.c :- This function sorts the userIDs using bubble sort algorithm 
</pre>	 

## Limitations
- If we call the loadTweetsFromFile function the very first time, all of the tweets are imported, but after this if we try to add tweets using createTweet, it is overwritten; but if called later, everything is appended to the tweetList!  
- A specific format of file is used for loadTweetsFromFile (id,user,text,)


## Future Improvements
- Memory leaks could be resolved<br>
- A better sorting algorithm could be used
