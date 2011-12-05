#!/bin/bash
# main script that will execute all operations.

#	2. k-means clustering
#		This script will look at all the processes and cluster them. Using (words,word occurances) as data, one can
#		see the processes themselves and cluster them based on the number of times evoked. 

echo "K-means clustering with output"
sh kmeans.bash
echo "Done with K-means clustering"



