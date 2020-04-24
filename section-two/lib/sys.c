 int assign_to_array(uint32_t num[25])
 {

   FILE *f;
   //unsigned int num[80];
   //uint32_t num[25];
	int i=0;
	int rv;
	int num_values;
	f=fopen("rm_hash.txt","r");
//	f=system("cat hex.txt |  tail -25 | tr -d '#'");

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

