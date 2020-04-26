# Section three

run-task-1:
	tail access.log

run-task-2:
	uniq access.log | sort -n | cut -d ' ' -f 1 | uniq

run-task-3:
	cut -d ' ' -f 3-6 access.log | grep "404" | cut -d ' ' -f 1-3

run-task-4:
	grep "Trident\|MSIE" access.log > access.ie.log

run-task-5:
# get the file into a $1request path $2proc_time
# Single-line Command below is working perfectly, only commented out to prevent duplicate creaction of the file1.log, file2.log and file3.log

#	cut -d ' ' -f 4,5,7 access.log | grep "[^/HTTP/1.1]" | grep -v "/ HTTP/1.1" >> file1.log | cut -d ' ' -f 1,3 file1.log >> file2.log | cut -c2-20 file2.log >> file3.log
	gcc task_five.c -o build/task_five
	./build/task_five

link: build/task_five.o build/sys.o
	gcc build/task_five.o build/sys.o -o build/task_five

build/task_five.o: task_five.c
	gcc tas_five.c -c -o build/task_five.o

build/sys.o:
	gcc lib/sys.c -c -o build/sys.o

run:
	./build/task_five

clean:
	rm -rf ./build && mkdir ./build
