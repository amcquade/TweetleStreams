# Tweetle Streams
A Hadoop-streams based search engine for tweets.

## Description
This project was an assignment from a course called "Distributed, Parallel, and Web-centric Computing".  This project was to help us understand the map and reduce algorithm and how a Hadoop job would run within the distributed file system.  Basically, the program searches a pool of Twitter tweets.  The program makes use of the bash shell, piping, and a basic unix sort to achieve this.  First, the tweets in JSON format are printed to standard output so that they can be read and processed by the mapper.  The arguments mapper takes are the hashtags you want to search for.  The mapper then processes the data line by line and by writing the tag if it matches the search criteria, along with the number one.  Next, the unix sort is called to arrange the tags in alphabetical order.  After that, the reducer combines all the tags that are the same that effectively sums the hashtags.  Finally we are left with the amount of times a given hashtag appears in the data.

## Usage
To run the program, consult the Makefile. 
