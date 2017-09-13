#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void help();

void help()
{
   printf("Usage: grep-lite [OPTION]... PATTERN\n"
	"Search for PATTERN in standard input. PATTERN is a\n"
	"string. grep-lite will search standard input line by\n"
	"line, and (by default) print out those lines which\n"
	"contain pattern as a substring.\n"
	"\n"
	"  -v, --invert-match     print non-matching lines\n"
	"  -n, --line-number      print line numbers with output\n"
	"  -q, --quiet            suppress all output\n"
	"\n"
	"Exit status is 0 if any line is selected, 1 otherwise;\n"
	"if any error occurs, then the exit status is 2.\n"); 

}

int main (int argc, char **argv)
{
  int i;
  int v = 0;
  int n = 0;
  int q = 0;
  int good = 0;
  int num = 1;

  for(i = 0; i < argc; ++i)
  {
    if(strcmp(*argv, "--help")==0)
    {
       help();
       
       return EXIT_SUCCESS;
    }
    else if(strcmp(*argv,"-v")==0 || strcmp(*argv,"--invert-match")==0)
      {v = 1;}
   else if(strcmp(*argv,"-n")==0 || strcmp(*argv,"--line-number")==0)
     {n = 1;}
   else if(strcmp(*argv,"-q")==0 || strcmp(*argv,"--quiet")==0)
    {q = 1;}
   else if(argv[i][0]=='-' && i != (argc-1) )
   {
     fprintf(stderr, "please pass usefull and meaningfull command");
      return 2;
   }
   argv++;
  }
if(argv[argc-1][0] == '-' || argc == 1)
{
  fprintf(stderr, "please change pattern!\n");
  return 2;
}

  char * str = malloc(2000*sizeof(char));
  if((v==0) && (q==0) && (n==0))
  {
      
      while(fgets(str, 2000, stdin))
    {
      if(str != NULL && strstr(str,argv[argc-1]))
      {
        fprintf(stdout,"%s", str);
	good = 1;
      }
    }
   }
  else if((q != 0) && (v==0))
 {
      
      while(fgets(str,2000,stdin))
   {
      if(str != NULL && strstr(str,argv[argc-1]))
      {
	    good = 1;
      }
   }
 }
  else if((q != 0) && (v != 0))
    {
      
      while(fgets(str,2000,stdin))
      {
	if(str != NULL && !strstr(str,argv[argc-1]))
	  {
	    good = 1;
	  }
      }
    }
  else if((v != 0) && (n == 0))
  {
      while(fgets(str,2000,stdin))
     {
	if(str != NULL && !strstr(str,argv[argc-1]))
	  {
	    fprintf(stdout,"%s", str);
	    good = 1;
	  }
      }
    }
  else if((v != 0) && (n != 0))
  {
      
    while(fgets(str, 2000, stdin))
    {
    if(str != NULL && !strstr(str,argv[argc-1]))
      {
	fprintf(stdout,"%d: %s",lineNum,str);
	    good = 1;
       }
	num++;
      }
    }
  else if(n != 0)
  {
     
    while(fgets(str, 2000, stdin))
    {
      if(strstr(str, argv[argc-1]))
      {
	fprintf(stdout,"%d: %s",num, str);
	      good = 1;
      }
	  num++;
    }
  }
  
  free(str);
  if(good != 0)
    {
      return 0;
    }
  return 1;
}



 
}
