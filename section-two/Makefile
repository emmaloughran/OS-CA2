#section one
task1:
	egrep -w '^#?([0-9A-Fa-f]{6}|[0-9A-Fa-f]{8})?' colours.txt
##	grep -ivE '^#([a-f0-9]{6}|[a-f0-9]{8})$$' colours.txt

task2:
##removing the # from the front of each valid hex number
	make task1 >output.txt
	tail -n+3 output.txt >hex.txt
	head -n -1 hex.txt > hex_values.txt
	cat hex_values.txt | tr -d '#'> hex_removed_hash.txt
##	rm output.txt hex.txt hex_values.txt
	gcc task_two.c -o build/task_two
	./build/task_two
	rm hex.txt output.txt removed_hash_prepended.txt  hex_values.txt hex_removed_hash.txt
