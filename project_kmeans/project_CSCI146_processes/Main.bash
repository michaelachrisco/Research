#!/bin/bash
# main script that will execute all operations.
#OPERATIONS:
#STEP 1: create sample data set 
#STEP 2: Use bag of words on sample documents
#STEP 3: Create a bag of words on MASTER (or all documents)
#STEP 4: AI analysis.

#options for script:
# -D Deletes all files except the scrips in the root folder. Will delete all folders except the root folder of the script.
# -i Ignores a step in the script if preprossessing has been done.


#DELETE OPTION - THIS WILL DELETE ALL OPERATIONS SO FAR
#ONLY USE IF YOU NEED TO REDO THE SCRIPT FROM SCRATCH.
#will put in deletion of folders later
if [ -n "$1" ] 
then
	if [ "$1" = "-D" ]
	then
		clear
		echo "Are you sure you want to delete everything and start over?[Y,N]"
		read option
		if [ "$option" = "Y" ]
		then 
			echo "DELETING EVERYTHING!"
			rm -rf Documents
			rm -rf Documents_BOW
			rm -rf MASTER
			rm -rf MASTER_BOW
			rm -rf AI
			mkdir Documents Documents_BOW MASTER MASTER_BOW AI
			cp kmeans/weights_equal_100.txt AI/weights_equal_100.txt
			cp kmeans/weights_unequal_100.txt AI/weights_unequal_100.txt
			echo "Done"
			exit
		fi
	fi

fi	
 
	

#STEP 1: create sample data set 
LIMIT=100
a=1
while [ "$a" -le $LIMIT ]
do
        echo "#1 Creating Sample data set $a"
	sh output_process_names.bash > Documents/document"$a"
        echo "#1 DONE"
a=$(($a+1))
done


#Create bag_of_words data from sample data

#where the documents with sample data is located.
FILES_IN=Documents/*

#where output for Bag of words operation
BOW_PATH=Documents_BOW/

#where MASTER is located
MASTER_PATH=MASTER/


#loop counter for the output
temp=0

#STEP 2: Use bag of words on sample documents

#for each document in the folder, do a bag of words operation and put the output in BOW_PATH
for f in $FILES_IN
do

  echo "Processing $f file..."
  # take action on each file. $f store current file name
  sh bag_of_words.bash $f $BOW_PATH"document"$temp"_BOW.txt"

temp=$(($temp+1))
done

#STEP 3: Create a bag of words on MASTER (or all documents)

#Create master document by recursivly concat all BOW_documents
cat $BOW_PATH* > $MASTER_PATH"MASTER.txt"

#path to Master with bag of words operaion done to it 
MASTER_BOW_PATH=MASTER_BOW/

#do the bag of words operation on the master document and create a global bag of words for all sample documents
echo "Processing MASTER.txt file..."
sh bag_of_words.bash $MASTER_PATH"*" $MASTER_BOW_PATH"MASTER_BOW.txt"

#STEP 4: AI analysis.
#	1. simple comparision
#		This script takes the current processes and compares them to the 
#		master bag of word model. It then prints out the results. 
#		The system administrator can use this information to see what processes
#		are being run that are not supposed to. 
#		Put simply, if Document A is the master and Document B is the new data,
#		the operation that will be involved will be: B not in A.
echo "Simple AI results: "
sh simple_AI.bash
echo "DONE with simple AI results"

#	2. k-means clustering
#		This script will look at all the processes and cluster them. Using (words,word occurances) as data, one can
#		see the processes themselves and cluster them based on the number of times evoked. 

echo "K-means clustering with output"
sh kmeans.bash
echo "Done with K-means clustering"



