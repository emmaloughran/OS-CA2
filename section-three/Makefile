# Section three

run-task-1:
	tail access.log

run-task-2:
	uniq access.log | sort -n | cut -d ' ' -f 1 | uniq

run-task-3:
	cut -d ' ' -f 3,4,5,6 access.log | grep "404" | cut -d ' ' -f 1,2,3

run-task-4:
	grep Trident access.log > access.ie.log
