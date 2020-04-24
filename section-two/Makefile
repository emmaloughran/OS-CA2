#section one
task1:
	egrep -w '^#?([0-9A-Fa-f]{6}|[0-9A-Fa-f]{8})?' colours.txt

task2:
##removing the # from the front of each valid hex number
	make task1 >hex.txt && cat hex.txt |  tail -26 | head -n -1 | tr -d '#' >rm_hash.txt
	gcc task_two.c -o build/task_two
	./build/task_two
	rm hex.txt

task3:
	gcc task_three.c -o build/task_three
	./build/task_three > rgba-colours.txt

clean:
	rm rgba-colours.txt rm_hash_preped0x.txt rm_hash.txt

