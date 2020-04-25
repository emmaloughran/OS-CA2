#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/sys.h"

#define MAX 100
#define MAXLINE 1024

void read_file(char *file_name);

request_data record[MAX];

int main () {

	char *file_name = "file3.log";

	read_file(file_name);

	return 0;

}

void read_file(char *file_name){

	FILE *in = fopen(file_name, "r");
	char *item;
	int rec_count = 0;
	char line[MAXLINE];
	int i;

	if(in == NULL){
		printf("Error opening file\n");
		return;
	}
	while(fgets(line, sizeof(line), in)){

		//printf("%s", line);

		item = strtok(line," ");
		strcpy(record[rec_count].request_path, item);

		item = strtok(NULL," ");
		record[rec_count].proc_time = atoi(item);

		rec_count++;

	}

	fclose(in);

	//loop through and reporr data

	printf("\tRequest Path\t\tProc_Time\n");
 	for (i = 0; i < rec_count; i++){
 			if(record[i].proc_time > 4){
					printf("\t%s\t\t\t%d\n",record[i].request_path, record[i].proc_time);
					printf("\n");
			}
	}


}
