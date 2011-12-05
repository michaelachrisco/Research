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


#seprate words from values
cat MASTER/MASTER.txt | awk '{print $1}'> AI/dictionary.txt
cat MASTER/MASTER.txt | awk '{print $2}'> AI/occurances.txt



#for each line in the dictionary, test to see if a line is the same. If it is, do not increment the counter. If both 
#strings are different, increment the counter. 
a=$(($a+0))
rm AI/dictionary_mapping.txt


#initializaiton
initial=" "
lastline=" "















while read eachline
do
	if [ "$lastline" = "$initial" ]
	then
		echo "first time around"
		read lastline 
		echo $eachline
		echo $lastline
		if [ "$eachline" = "$lastline" ]
		then
			echo $a"\n"$a >> AI/dictionary_mapping.txt
			echo "same"
			echo $a"\n"$a
		else
			echo $a	>> AI/dictionary_mapping.txt	
			a=$(($a+1)) 
			echo $a	>> AI/dictionary_mapping.txt
		fi
	else
		if [ "$lastline" = "$eachline" ]
		then
			echo $a >> AI/dictionary_mapping.txt		
		else
			a=$(($a+1)) 
			echo $a >> AI/dictionary_mapping.txt	 
		fi
	lastline=$eachline	
	fi
done < AI/dictionary.txt


#combine the dictionary mapping file to the occurances file

paste AI/dictionary_mapping.txt AI/occurances.txt > AI/points_100.txt


	
		
./kmeans_test

gnuplot plot.p

echo "see results in AI/output.png"
