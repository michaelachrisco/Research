#!/bin/bash
#how to use:
# sh bag_of_words.bash document_input_path_and_name document_output_path_and_name

#input path
if [ -n "$1" ] 
then
	PATH_IN="$1"
else
	echo "no path to input specified. ERROR"
	exit
fi

#output path
if [ -n "$2" ]
then 
	PATH_OUT="$2"
else
	echo "no path to output specified. ERROR"
fi	


#For Debug
echo "PATH IN: "$PATH_IN


cat $PATH_IN | tr ' ' '\
' | tr '[:upper:]' '[:lower:]' | 
tr -d '[:punct:]' | grep -v '[^a-z]' | 
sort | uniq -c | awk '{if ($1 != "" && $2!="") print $2" "$1;}' | sort > $PATH_OUT

echo "PATH OUT: "$PATH_OUT

#will give number of occurances words are used in file with the corresponding words
