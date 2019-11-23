------------------------------
Abbas Engineer
afengine
CS101 Patrick Tantalo
README
------------------------------

Programming Assignment  1

Build an Integer List ADT and use it to alphabetize the lines in a file

List.java: Acts as an ADT for linked list. bi-directional queue that includes a cursor to be used for iteration.
the cursor may be undefined, it's default state. The list has two ends referred to as front and back.
Used the examples given of the Queue to begin with creating an empty list and used the dequeue similar to deleteFront 
and Enqueue similar to append. then used Stack and realized that pop is deleteBack. That was a good starting point.
The cursor will be used by the client to traverse the list in either direction. Each list element is associated with
an index ranging from 0 (front) to n-1 (back), where n is the length of the list
conains all the functions necessary for manipulating and accessing any part of the linked list. All mandatory functions were built. 


Make File: Used to run the program holds commands to run on timeshare.
Given by the Professor

ListClient.java: to serve as a test client for ADT checking if functions work.
(Not a thorough Test )
Given by the Professor

Lex.java: This is the main program for this project. Lex.java takes two command line arguments giving the 
names of an input file and an output file.Used the examples given from FileIO as starting point on how to 
read begin reading the file and counting the lines. The input can be any text file.The output file contains the same 
lines as the input arranged in alphabetical order. Counting the number of lines n in the file named by args[0]. 
Creating a String array of length n and read in the lines of the file as Strings, placing them into the array.
Creating a List whose elements are the indices of the above String array. These indices are arranged in
an order that effectively sorts the array. Starting with an empty List, then inserting the indices of the
array one by one into the appropriate positions of the List. Using the InsertionSort algorithm as a guide.


