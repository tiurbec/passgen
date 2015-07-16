#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

void help()
{
   printf("passgen       Random passwords generator\n");
   printf("\n");
   printf("Usage: useradd [options]");
   printf("\n");
   printf("Options:\n");
   printf("  -l len      Specify the length of generated passwords\n");
   printf("  -c count    How many random passwords to be generated\n");
   printf("  -a          Passwords will contain only small letters\n");
   printf("  -A          Passwords will also contain capital letters\n");
   printf("  -n          Passwords will also contain numbers\n");
   printf("  -s          Passwords will also contain symbols\n");
   printf("\n");
   printf("Default options:\n");
   printf("  passgen -l 10 -c 1 -a\n");
   printf("\n");
}
int main(int argc, char *argv[])
{
   int i,j;
   int passlen=10;
   int passcount=1;
   int alpha=1;
   int capitals=1;
   int numbers=1;
   int symbols=0;
   int max=26;
   char letters[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                   'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                   '0','1','2','3','4','5','6','7','8','9',
                   '.',',','!','@','#','$','%','^','&','*','(',')','[',']','{','}',':',';','~','<','>','/','+','-' };
/*   for (i=0;i<argc;i++)
       printf("%s ",argv[i]);*/
   srand(time(NULL));
   for (i=1;i<argc;i++)
   {
	if (strcmp(argv[i],"-l")==0)
	{
	   i++;
	   passlen=atoi(argv[i]);
	} else
        if (strcmp(argv[i],"-c")==0)
        {
           i++;
           passcount=atoi(argv[i]);
        } else
        if (strcmp(argv[i],"-a")==0)
        {
           max=26;
        } else
        if (strcmp(argv[i],"-A")==0)
        {
           max=52;
        } else
        if (strcmp(argv[i],"-n")==0)
        {
           max=62;
        } else
        if (strcmp(argv[i],"-s")==0)
        {
           max=86;
        } else
	{
	   printf("Invalid param: %s\n\n",argv[i]);
	   help();
	   return 255;
	}

   }
   for (i=0;i<passcount;i++)
   {
	for (j=0;j<passlen;j++)
	{
	   printf("%c",letters[rand()%max]);
 	}
	printf("\n");
   }
}
