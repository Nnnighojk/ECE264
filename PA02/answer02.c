#include <stdio.h>
#include <string.h>
#include <stdlib.h>  

#include "answer02.h"

char * strcat_ex(char * * dest, int * n, const char * src)
{ 
   int i  = 0;
   char *buffer;
   if((*dest == NULL) || (strlen(*dest)) + (strlen(src)) > *n )
    {
       if((strlen(*dest) != 0) && (strlen(src) != 0))
        {
           int buffer = malloc(1 + 2*(strlen(*dest)) + (strlen(src)));
           *n = 1 + 2*(strlen(*dest)) + (strlen(src));
        }
       else if (*dest == NULL)
        {
           int buffer = malloc(1 + 2 * (strlen(src)));
           *n = 1 + 2 * (strlen(src));
        }
        
        
        buffer[i] = '\0';
      
       if( (buffer != NULL) && (* dest != 0))
       {
          strcpy(buffer, *dest);
       }
      
       else if ((*dest != 0))
       {
     
          free(*dest);
       }

       *dest = buffer;
        strcat(*dest, src);
   }
  

   else if (src == NULL)
   {
       return ((char*)dest);
   }
      return ((char*)dest);
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
  *arrLen = 1;
  char **string;
  int i = 0;
  int j = 0;
  int end = 0;
  int a = 0;
  while(*str != '\0')
    {
      if (strchr(delims, *str))(*arrLen)++;
      str++;
    }

  string = malloc(*arrLen * sizeof(char *));

  for ( i = 0; *str != '\0'; i++ )
  {
    if ( strchr ( delims, str[i] ) != NULL )
     {
			
       string[j] =  malloc ( ( i - end + 1 ) * sizeof ( char ) );

				
	for ( a = 0 ; end < i; end++, a++ )
	{
	  string[j][a] = str[end];
	}
	  string[j][a] = '\0';

	  end = i + 1;

	  j++;
			
     }
   }
  string[j] = malloc ( ( i - end + 1 ) * sizeof ( char ) );
  memcpy(string[j], *str, a * sizeof(char));
  string[j][a] = '\0';

 return string;
}

char * implode(char * * strArr, int len, const char * glue)
{
   int i;
   int length = 0;
   char *ret;

   for (i = 0; i < len ; i++)
   { 
      if( *strArr != NULL)
      { 
        length += strlen(strArr);
    
      }
     strArr++;
   }

   length += strlen ( glue ) * i + 1;
   ret = malloc ( length * sizeof ( char ) );
   ret[0] = '\0';

   ret = strcat_ex ( &ret, &length, strArr[0] );
   strcat ( ret, glue );

   for ( i = 1; i < len - 1; i++ )
   {
       strcat ( ret, *strArr);
       strcat ( ret, glue );
       strArr++;
   }
 
    //strcat ( ret, *strArr );

   return ret;
   
}


int cmpstringp(const void *p1, const void *p2)
{ 
  const char **p3 = (char const **) p1;
  const char **p4 = (char const **) p2;
  return strcmp(*p3,*p4);
  
}

void sortStringArray(char * * arrString, int len)
{
   qsort(arrString, len, sizeof(char *), cmpstringp);

}

int compare_s (const void *ptr1, const void *ptr2)
{ 
   return(strcmp((char const *)ptr1 ,(char const *)ptr2));
}

void sortStringCharacters(char * str)
{
  qsort(str, strlen(str), sizeof(char), compare_s);
}

void destroyStringArray(char * * strArr, int len)
{
   int i = 0;
   
   for(i = 0;i < len; i++)
   {
      free(*strArr);
      strArr++ ;
   }
   
   free(strArr);
}
     
