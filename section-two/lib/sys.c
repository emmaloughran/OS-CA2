 int assign_to_array(uint32_t num[25])
 {

   FILE *f;
   //unsigned int num[80];
   //uint32_t num[25];
   int i=0;
   int rv;
   int num_values;

   f=fopen("removed_hash_prepended.txt","r");
 //  f=fopen("removed_hash_prepended.txt","r");
 //  f=fopen("hex_removed_hash.txt","r");
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

