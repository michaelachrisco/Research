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

#BOW algorithm. Takes individual words and creates a list of unique words for document. 
cat $PATH_IN | tr ' ' '\
' | sort | uniq | sort >$PATH_OUT

#For Debug
echo "PATH OUT: "$PATH_OUT

