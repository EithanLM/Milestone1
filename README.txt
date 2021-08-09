Authors:
Daniel Putter 327577789
Eithan Rospsha 215219882

How to use:
The arguments to main: the path to the classified data, then the path to the unclassified data,
then the path to the output file. Exactly 3 are required or default values will be used.
The amount of neighbors k is received from the console.

How it works:
We use the KNN algorithm to classify.
In our implementaion we compare the distances from all the categories and save in the list and
take the closest k according to the k given in the console.
We then printed the data that was in the unclassified file to an output file in the same format as the classified file.
