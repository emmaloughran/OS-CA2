#Section one

#[1]
run-task-1:
	printf "The quick brown fox jumps over the lazy dog \n" | wc -w

#[2]- using tr
run-task-2:
	printf "The quick brown fox jumps over the lazy dog \n"  | tr [:lower:] [:upper:]

#[3] - use of curl
run-task-3:
	curl https://www.dkit.ie > dkit.html

#[4]- use of tr- find and replace
#[5]- use of head and tail 
run-task-4:
	tail -1 dkit.html | tr '<>' '[]' >> mangled.txt && printf "\n" >>mangled.txt && head -1 dkit.html | tr '<>' '[]' >> mangled.txt

clean:
	unlink mangled.txt && unlink dkit.html
