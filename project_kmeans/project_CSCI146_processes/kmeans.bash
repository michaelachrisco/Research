#k-means clustering using executable.
#given a set of strings, get the occurances from the documents and create a
#(X,Y) corrdinate based on (word, word occurance)

#Will use the MASTER.txt as the dataset for k-means clustering and gnuplot
#for graphing the results.

#1. use Master.txt to get bag_of_words with word occurances. This will create
#a word frequency vector and put the data into 
#AI/kmeans_BOW.txt as the data set.

sh bag_of_words_without_punc.bash MASTER/MASTER.txt AI/kmeans_BOW.txt

#now that we have the occurances in AI/kmeans_BOW.txt, we will map a number to each word. For example A 10, B 20 will have A =>0 and B=>1 so the data set will look like 0 10, 1 20 for the kmeans algorithm. K-means only accepts numerical data. 


#for ouput only, no storing of actual results.
while read eachline
do
a=$(($a+1))
echo "$a "$eachline |awk '{print $1,"Is now mapped to: ",$3}'
done < AI/kmeans_BOW.txt

rm 
a=$((0))
while read eachline
do
a=$(($a+1))
echo "$a "$eachline |awk '{print $1,$2}' >> AI/points_100.txt
done < AI/kmeans_BOW.txt

#do the kmeans test on the sample data in points_100.txt and create clusters
./kmeans_test

gnuplot plot.p

echo "see results in AI/output.png"

