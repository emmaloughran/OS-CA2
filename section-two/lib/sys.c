#define VALID_HEX 25
//[6] reading from a file
 int assign_to_array(uint32_t num[VALID_HEX])
 {

	FILE *f;
	int i=0;
	int rv;
	int num_values;
	//fopen to open a file. "r" is used becuase I am reading from the file
	f=fopen("rm_hash.txt","r");
	while (i <= VALID_HEX)
	{
	//"%x" used to stor the number in hex format
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
//loop through each number in the array and continuously divide it by 10 until there is nothing left and add up the number of times this occurs-
//the number in the array is not set to 0, so need to assign to array again.
//save the count of the numebr of times to count array so i know how many digits are in the ith  element
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

