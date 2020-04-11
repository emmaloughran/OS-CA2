###Section one

task1:
	printf "The quick brown fox jumps over the lazy dog \n" | wc -w

#source[1]- using tr
task2:
	printf "The quick brown fox jumps over the lazy dog \n"  | tr [:lower:] [:upper:]

#source[2] - use of curl
task3:
	curl https://www.dkit.ie > dkit.html

#source[1]- use tr
task4:
	tail -1 dkit.html | tr '<>' '[]' >> mangled.txt
	printf "\n" >>mangled.txt
	head -1 dkit.html | tr '<>' '[]' >> mangled.txt
