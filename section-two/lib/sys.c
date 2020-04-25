//[6] reading from a file
 int assign_to_array(uint32_t num[25])
 {

   FILE *f;
	int i=0;
	int rv;
	int num_values;
	f=fopen("rm_hash.txt","r");
	while (i <= 25)
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
int check_len(uint32_t num[25],int count[25])
{

	for(int i=0;i<25;i++)
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

