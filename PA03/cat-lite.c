#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void help_m();
int output (char *);

void help_m()
{
	
	printf("Usage: cat-lite [--help] [FILE]...\n"
	"With no FILE, or when FILE is -, read standard input.\n"
	"\n"
	"Examples:\n"
	"  cat-lite README   Print the file README to standard output.\n"
	"  cat-lite f - g    Print f's contents, then standard input,\n"
	"                    then g's contents.\n"
	"  cat-lite          Copy standard input to standard output.\n");
	
}

int output (char *f)
{
  int a;
  if(strcmp(f,"-")==0)
  {
    while(!feof(stdin))
    {
      a = fgetc(stdin);
      if(a>0)		
      fputc(a,stdout);
    }
     return EXIT_SUCCESS;
  }
	
    FILE *file = fopen(f, "r");
    if(file == NULL)
    {
      return EXIT_FAILURE;
    }
    while(!feof(file))
    {
      a = fgetc(file);
      if(a>0)		
      fputc(a, stdout);
    }
    fclose(file);
    return EXIT_SUCCESS;

}


int main (int argc, char ** argv)
{ 
   int i;
   int s = 0;

   if(argc==1)
   {
     output("-");
     return EXIT_SUCCESS;
   }
   
   for(i = 1; i < argc; ++i)
   {
     if(strcmp(argv[i],"--help")==0)
     {
        help_m();
        
       return EXIT_SUCCESS;
     } 
       
   }
  for(i = 1; i < argc; ++i)
  {
    s = output(argv[i]);
    if(s == EXIT_FAILURE)
    {
      fprintf(stderr,"cat cannot open %s\n", *argv);
      return EXIT_FAILURE;
    } 
    
  }
  
	return EXIT_SUCCESS;


}
