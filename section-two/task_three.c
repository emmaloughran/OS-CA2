#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "./lib/sys.c"


struct colors {	
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
}rgb[24];


	int rgba_values(uint32_t num[24],struct colors rgb[]);
	int check_len(uint32_t num[24], int count[24]);
	int append_0x();
	int assign_to_array_prepend(uint32_t num[24]);
	int appendff(int count[25], uint32_t num[24]);
	void sort_by_a(struct colors rgb[]);
	void print(struct colors rgb[]);
int main ()
{
	int count [24] ={0};
	uint32_t num [24];


	append_0x();
	assign_to_array_prepend(num);
	check_len(num,count);
	appendff(count,num);
	rgba_values(num,rgb);
	sort_by_a(rgb);
	print(rgb);

}

void print(struct colors rgb[])
{
	for(int i=0;i<=24;i++)
	{
		printf("rgba(%u,%u,%u,%u)\n", rgb[i].r,rgb[i].g,rgb[i].b,rgb[i].a);
	}
}

void sort_by_a(struct colors rgb[])
{
//reference [4]- used parts of material from stack overflow to help with this sort func$
	struct colors temp;
	int i,j;
	//loop through all of the colors
	for( i = 0; i <=24; i++)
	{
		for(j=i+1;j<=24;j++)
		{
   //compare the a color in the first loop with the second
			if(rgb[i].a > rgb[j].a)
			{
	 //if the if statment above is true, store the info in in temp and move the values fro$
				temp=rgb[i];
				rgb[i]=rgb[j];
				rgb[j]=temp;
			}
  	}
	}
}




int appendff(int count[24], uint32_t num[24])
{
	uint32_t extra_hex= 0xFF;

	for (int i=0; i<=24; i++)
	{
		if(count[i]<9)
		{
			num[i] = (num[i]<<8) | extra_hex;
		}
	}

	return 0;

}



int rgba_values(uint32_t num[24],struct colors rgb[] )
{

	for(int i=0;i<=24;i++)
	{
		rgb[i].r = (num[i] &0xFF000000) >>24;
		rgb[i].g = (num[i] &0x00FF0000) >>16;
		rgb[i].b = (num[i] &0x0000FF00) >>8;
		rgb[i].a = (num[i] &0x000000FF);
	};

	return 0;

}


int check_len(uint32_t num[24],int count[24])
{

	for(int i=0;i<=24;i++)
	{
		do
		{
			count[i]++;
			num[i] /= 10;
		} while(num[i] != 0);

	}

	assign_to_array_prepend(num);

	return 0;
}

int append_0x()
{

	FILE *fr, *fw;
	char buffer[10000];
	fr = fopen("rm_hash.txt","rt");

	if (fr == NULL)
	{
		printf("Error opening input file\n");
		return 1;
	}

	fw = fopen("rm_hash_preped0x.txt","wt");

	if (fw==NULL)
	{
		printf("Error opening output file\n");
		fclose (fr);
		return 1;
	}

	while (fgets(buffer, 10000, fr) != NULL)
	{
		buffer [ strcspn(buffer, "\r\n") ] = 0;   // remove trailing newline etc
		fprintf(fw, "0x%s\n", buffer);
	}

	fclose(fw);
	fclose(fr);
	return 0;

	}


int assign_to_array_prepend(uint32_t num[24])
{
	FILE *f;
	int i = 0;
	int rv;
	f=fopen("rm_hash_preped0x.txt","r");

	if (f==NULL)
	{
		printf("unknown file\n");
		return 1;
  }

	while (i <= 24)
	{
		rv = fscanf(f, "%x", &num[i]);
	  i++;
  }

  fclose(f);
  return 0;

  }
