#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
}rgb;

int append_0x();
int assign_to_array(uint32_t num[25]);
int  extract_green(uint32_t num[25]);

int main()
{
uint32_t num[25];	

	append_0x();
	assign_to_array(num);
	extract_green(num);
	
}

int append_0x()
{

	FILE *fr, *fw;
	char buffer[10000];
	fr = fopen("hex_removed_hash.txt","rt");
	if (fr == NULL) {
		printf("Error opening input file\n");
		return 1;
	}

	fw = fopen("removed_hash_prepended.txt","wt");

	if (fw==NULL) {
		printf("Error opening output file\n");
		fclose (fr);
		return 1;
	}

	while (fgets(buffer, 10000, fr) != NULL) {
	buffer [ strcspn(buffer, "\r\n") ] = 0;   // remove trailing newline etc
	fprintf(fw, "0x%s\n", buffer);
	}
	

	fclose(fw);
	fclose(fr);
	return 0;

}


int assign_to_array(uint32_t num[25])
{

	FILE *f;
	//unsigned int num[80];
	//uint32_t num[25];
	int i=0;
  int rv;
  int num_values;

 	f=fopen("removed_hash_prepended.txt","r");
//	f=fopen("removed_hash_prepended.txt","r");
//	f=fopen("hex_removed_hash.txt","r");
  if (f==NULL){
  	printf("unknown file\n");
    return 1;
	}

	while (i <= 25) {
  	rv = fscanf(f, "%x", &num[i]);

		if (rv != 1)
    	break;
			i++;
    }
		fclose(f);
    return 0;
}


int extract_green(uint32_t num[25])
{
 //  uint32_t hexval = argv;
	uint8_t green_vals [25];
	printf("GREEN VALUES \n");
	for(int i=0;i<25;++i)
	{
		green_vals[i]=(num[i]>>8)& 0xff;
		printf("%02x,",green_vals[i]);
	}
	printf("\n");

	return 0;



}
