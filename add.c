#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char ** argv){


	FILE *read = fopen("list.txt", "r");
    if (!read) {
      perror ("Error reading from list.txt!\n");
      return 1;
    }
    char fileText[1337];
    fgets(fileText, 1337, read);
    int num = atoi(fileText)+1;
    fclose (read);

  //  puts("heyo");

	FILE *append;
	append=fopen("list.txt", "a");
	fprintf(append, "%d: %s\n",num,argv[1]);
	fclose(append);


   char buf[100];
   sprintf(buf, "sed '1d' list.txt > temp.txt && perl -pi -e 'print \"%d\n\" if $. == 1' temp.txt && cp temp.txt list.txt", num); // puts string into buffer
   system(buf);
   printf("Added. You've set %d tasks so far\n",num);

}