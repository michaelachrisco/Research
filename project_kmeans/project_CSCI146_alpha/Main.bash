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
		echo "DELETING EVERYTHING!"
	fi
	
fi





#STEP 1: create sample data set 
echo "#1 Creating Sample data set"
echo "#1 DONE"


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



