###Section one

task1:
	printf "The quick brown fox jumps over the lazy dog \n" | wc -w

task2:
	printf "The quick brown fox jumps over the lazy dog \n"  | tr [:lower:] [:upper:]

task3:
	curl https://www.dkit.ie > dkit.html
