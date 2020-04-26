#Source [1]Regex for hex color codes
#souce [2] using egrep with regex
run-task-1:
##regex to check that the number starts with a hash, is either 6 or 8 chars long and only contains letters a-f, upper or lower case and digits in the range 0-9, no negative numbers
	egrep -w '^#?([0-9A-Fa-f]{6}|[0-9A-Fa-f]{8})?' colours.txt

run-task-2:
##removing the # from the front of each valid hex number
#source[3] using head and tail
#source[4] using tr and -d flag
##save output from task1 into hex.txt and remove the first and last line. Remove the # from the start of each line. Then run C program
	make run-task-1 >hex.txt && cat hex.txt |  tail -26 | head -n -1 | tr -d '#' >rm_hash.txt
	gcc task_two.c -o build/task_two
	./build/task_two

run-task-3:
#source[9] sorting a csv file
##direct output from C program to a CSV file. Sort the CSV file according to its 4th column delimited by ',' and redirect that output to  rgba-colours.txt
	gcc task_three.c -o build/task_three
	./build/task_three > output.csv
	sort -t\, -n -k4,4 output.csv	> rgba-colours.txt


clean:
	##rm rgba-colours.txt rm_hash_preped0x.txt rm_hash.txt
	rm  rm_hash_preped0x.txt rm_hash.txt rgba-colours.txt hex.txt output.csv  ./build/task_two ./build/task_three

