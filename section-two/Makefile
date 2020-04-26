#Source [1]Regex for hex color codes
#souce [2] using egrep with regex
run-task-1:
	egrep -w '^#?([0-9A-Fa-f]{6}|[0-9A-Fa-f]{8})?' colours.txt

run-task-2:
##removing the # from the front of each valid hex number
#source[3] using head and tail
#source[4] using tr and -d flag
	make run-task-1 >hex.txt && cat hex.txt |  tail -26 | head -n -1 | tr -d '#' >rm_hash.txt
	mkdir build
	gcc task_two.c -o build/task_two
	./build/task_two
	rm hex.txt -r build/

run-task-3:
#source[9] sorting a csv file
	mkdir build
	gcc task_three.c -o build/task_three
	./build/task_three > output.csv
	sort -t\, -n -k4,4 output.csv	> rgba-colours.txt
	rm output.csv -r build/


clean:
	##rm rgba-colours.txt rm_hash_preped0x.txt rm_hash.txt
	rm  rm_hash_preped0x.txt rm_hash.txt rgba-colours.txt 


