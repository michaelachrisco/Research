echo "type in file name"
read filename


cat $filename | tr ' ' '\
' | tr '[:upper:]' '[:lower:]' | 
tr -d '[:punct:]' | grep -v '[^a-z]' | 
sort | uniq -c | sort -rn 

#will give number of occurances words are used in file with the corresponding words
