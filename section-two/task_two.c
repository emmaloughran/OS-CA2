#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "./lib/sys.c"
#define VALID_HEX 25

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
}rgb;

//int append_0x();
int  extract_green(uint32_t num[25]);

int main()
{
	uint32_t num[25];	

	assign_to_array(num);
	extract_green(num);

}

int extract_green(uint32_t num[25])
{
 //  uint32_t hexval = argv;
	uint8_t green_vals [VALID_HEX];
	printf("\nGREEN VALUES \n\n");

	for(int i=0;i<VALID_HEX;++i)
	{
		green_vals[i]=(num[i]>>8)& 0xff;
		printf("%u,",green_vals[i]);
	}
	printf("\n\n");

	return 0;


}
