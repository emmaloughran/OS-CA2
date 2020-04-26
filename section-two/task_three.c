#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "./lib/sys.c"
#define VALID_HEX 25
#define EIGHT_DIGIT_HEX 9

struct colors {	
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
}rgb[VALID_HEX];

int rgba_values(uint32_t num[VALID_HEX],struct colors rgb[]);
int check_len(uint32_t num[VALID_HEX], int count[VALID_HEX]);
int append_0x();
int assign_to_array_prepend(uint32_t num[VALID_HEX]);
int appendff(int count[VALID_HEX], uint32_t num[VALID_HEX]);
void print(struct colors rgb[]);

int main ()
{
	int count [VALID_HEX] ={0};
	uint32_t num [VALID_HEX];

	append_0x();
	assign_to_array_prepend(num);
	check_len(num,count);
	appendff(count,num);
	rgba_values(num,rgb);
	print(rgb);

}

void print(struct colors rgb[])
{
	for(int i=0;i<VALID_HEX;i++)
	{
		printf("rgba(%u,%u,%u,%u)\n", rgb[i].r,rgb[i].g,rgb[i].b,rgb[i].a);
	}
}

//[10] concantenatign in C
int appendff(int count[VALID_HEX], uint32_t num[VALID_HEX])
{
	uint32_t extra_hex= 0xFF;

	for (int i=0; i<=VALID_HEX; i++)
	{
		if(count[i] < EIGHT_DIGIT_HEX)
		{
			num[i] = (num[i]<<8) | extra_hex;
		}
	}
	return 0;
}


//source [5] bitwise operations
int rgba_values(uint32_t num[VALID_HEX],struct colors rgb[] )
{

	for(int i=0;i<=VALID_HEX;i++)
	{
		rgb[i].r = (num[i] &0xFF000000) >>24;
		rgb[i].g = (num[i] &0x00FF0000) >>16;
		rgb[i].b = (num[i] &0x0000FF00) >>8;
		rgb[i].a = (num[i] &0x000000FF);
	};

	return 0;

}

//[8] writing to a file
int append_0x()
{

	FILE *fr, *fw;
	char buffer[10000];
	fr = fopen("rm_hash.txt","rt");

	fw = fopen("rm_hash_preped0x.txt","wt");

	while (fgets(buffer, 10000, fr) != NULL)
	{
		buffer [strcspn(buffer, "\r\n")] = 0;   // remove trailing newline etc
		fprintf(fw, "0x%s\n", buffer);
	}

	fclose(fw);
	fclose(fr);
	return 0;

	}

//[6]
int assign_to_array_prepend(uint32_t num[VALID_HEX])
{
	FILE *f;
	int i = 0;
	int rv;
	f=fopen("rm_hash_preped0x.txt","r");
	while (i <= VALID_HEX)
	{
		rv = fscanf(f, "%x", &num[i]);
	  i++;
  }

  fclose(f);
  return 0;

  }
