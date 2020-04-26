#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
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
	int p_shortest = INT_MAX;
	int v_shortest = INT_MAX;
	int p_longest = INT_MIN;
	int v_longest = INT_MIN;
	float p_total = 0.0;
	float v_total = 0.0;
	float p_average;
	float v_average;

	int p_count = 0;
	int v_count = 0;

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


	//loop through and report data

	printf("\tRequest Path\t\tProc_Time\n");
	printf("\t-----------------------------------\n");
 	for (int i = 0; i < rec_count; ++i){

 			if(record[i].proc_time > 4){
				printf("\t%s\t\t%d\n",record[i].request_path, record[i].proc_time);

 				if (strcmp(record[i].request_path,"portfolio") == 0){

 						if(record[i].proc_time < p_shortest){
								p_shortest = record[i].proc_time;
						}
						if(record[i].proc_time > p_longest){
								p_longest = record[i].proc_time;

						}

						p_total += record[i].proc_time;
						p_count++;
 				}

 				if (strcmp(record[i].request_path,"videos") == 0){

						if (record[i].proc_time < v_shortest){
								v_shortest = record[i].proc_time;
						}
						if(record[i].proc_time > v_longest){
								v_longest = record[i].proc_time;
						}
						v_total += record[i].proc_time;
 						v_count++;
 				}

				printf("\n");
			}
	}

	p_average = p_total / p_count;
	v_average = v_total / v_count;

	printf("Total number of request for Portfolio = %d\n", p_count);
	printf("Total number of request for Videos = %d\n", v_count);

	printf("\nShortest request time for the Portfolio path = %d\n", p_shortest);
	printf("Longest request time for the Portfolio path = %d\n", p_longest);

	printf("\nShortest request time for Videos path = %d\n", v_shortest);
	printf("Longest request time for videos path = %d\n", v_longest);

	printf("\nAverage request time for Portfolio = %.2f\n", p_average);
	printf("Average request time for Videos = %.2f\n", v_average);

}
