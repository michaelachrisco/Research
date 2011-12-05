#!/etc/bash
#Michael Chrisco

#Script does a simple comparision bewtween new processes and those already in the dataset.

#Compare current running processes and the Master_BOW.txt file
sh output_process_names.bash > AI/SIMPLE.txt
sh bag_of_words.bash AI/SIMPLE.txt AI/SIMPLE_BOW.txt
diff AI/SIMPLE_BOW.txt MASTER_BOW/MASTER_BOW.txt >AI/SIMPLE_AI_RESULTS.txt
cat AI/SIMPLE_AI_RESULTS.txt
