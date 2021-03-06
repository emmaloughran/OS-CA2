#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "./lib/sys.c"
#include "./lib/sys.h"
#define VALID_HEX 25

int  extract_green(uint32_t num[VALID_HEX],int count[VALID_HEX]);
int check_len(uint32_t num[VALID_HEX],int count[VALID_HEX]);

int main()
{
	int count[VALID_HEX]={0};
	uint32_t num[VALID_HEX];	

	//assign all lines of the hex numbers text file to an array
	assign_to_array(num);
	//check the lenght of each array element- whether they are 6 or 8 characters in length
	check_len(num,count);
	//extract the green value from each array element based on whether they are 6 or 8 characters in length
	extract_green(num,count);

}

//[5] bitwise operations
int extract_green(uint32_t num[VALID_HEX], int count[VALID_HEX])
{
 //  uint32_t hexval = argv;
	uint8_t green_vals [VALID_HEX];
	printf("\nGREEN VALUES \n\n");

	for(int i=0;i<VALID_HEX;++i)
	{
		if(count[i]<9)
		{
			green_vals[i]=(num[i]>>8)& 0xff;
		}
		else
		{
			green_vals[i]=(num[i]>>16)& 0xff;
		}

		printf("%u,",green_vals[i]);
	}
	printf("\n\n");

	return 0;
}

