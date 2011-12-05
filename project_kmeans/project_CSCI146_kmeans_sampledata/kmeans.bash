#k-means clustering using executable.
#given a set of strings, get the occurances from the documents and create a
#(X,Y) corrdinate based on (word, word occurance)

#Will use the MASTER.txt as the dataset for k-means clustering and gnuplot
#for graphing the results.

#1. use Master.txt to get bag_of_words with word occurances. This will create
#a word frequency vector and put the data into 
#AI/kmeans_BOW.txt as the data set.

#sh bag_of_words_without_punc.bash MASTER/MASTER.txt AI/kmeans_BOW.txt

#now that we have the occurances in AI/kmeans_BOW.txt, we will map a number to each word. For example A 10, B 20 will have A =>0 and B=>1 so the data set will look like 0 10, 1 20 for the kmeans algorithm. K-means only accepts numerical data. 

./kmeans_test

gnuplot plot.p

echo "see results in AI/output.png"
