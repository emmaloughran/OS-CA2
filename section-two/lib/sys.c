#define VALID_HEX 25
//[6] reading from a file
 int assign_to_array(uint32_t num[VALID_HEX])
 {

   FILE *f;
	int i=0;
	int rv;
	int num_values;
	f=fopen("rm_hash.txt","r");
	while (i <= VALID_HEX)
	{
		rv = fscanf(f, "%x", &num[i]);
		if (rv != 1)
			break;
			i++;
		}

		fclose(f);
		return 0;
 }

//[7]
int check_len(uint32_t num[VALID_HEX],int count[VALID_HEX])
{

	for(int i=0;i<= VALID_HEX;i++)
	{
		do
		{
			count[i]++;
			num[i] /= 10;
		} while(num[i] != 0);
	}

	assign_to_array(num);
	return 0;
   }

