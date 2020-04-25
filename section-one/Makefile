#Section one

#[1]
task1:
	printf "The quick brown fox jumps over the lazy dog \n" | wc -w

#[2]- using tr
task2:
	printf "The quick brown fox jumps over the lazy dog \n"  | tr [:lower:] [:upper:]

#[3] - use of curl
task3:
	curl https://www.dkit.ie > dkit.html

#[4]- use of tr- find and replace
#[5]- use of head and tail 
task4:
	tail -1 dkit.html | tr '<>' '[]' >> mangled.txt && printf "\n" >>mangled.txt && head -1 dkit.html | tr '<>' '[]' >> mangled.txt

clean:
	unlink mangled.txt && unlink dkit.html
