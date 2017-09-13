#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
  int i;
  
  for(i = 1; i < argc; ++i)
  {
    fprintf(stdout, "%s", argv[i]);
    
  }
 
 printf("\n");
 return EXIT_SUCCESS;
}
