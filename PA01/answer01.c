
#include "answer01.h"
#include <stdio.h>

// NOTE: You are NOT to use the strings library on this assignment,
// as stated in the README.
// DO NOT BEGIN WORKING ON THIS FILE UNTIL YOU HAVE COMPLETELY AND
// THOROUGHLY READ THE README FILE!!!

int arraySum(int * array, int len)
{   //local declarations
    int sum = 0;
    int i = 0;

    // executables
    for(i = 0; i < len; i++)
      {
        sum = sum + *array;
        array++;
      }
   
     return (sum);
        
    
}

int arrayCountNegative(int * array, int len)
{
    //local declarations
    int i = 0;
    int count = 0;
    
    // executables
    for(i = 0; i < len; i++)
     { 
       if ( *array < 0)
        {
           count++;
        }
       array++;
     }
    
     return (count);
}

int arrayIsIncreasing(int * array, int len)
{    
    //local declarations
    int i = 0;
    int count = 1;
  
    //executables
    for(i = 0; i < (len - 1); ++i)
      {
        
         if (*array  > *(array+1))
         {
            count = 0;
         }
        
        array++;
      }
        
      return(count); 
           
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    //local declarations
     int index = -1;
     int i = 0;

   //executables
    while (i < len)
      {
        if(needle == *haystack)
         {
           index = i;
         }
       
       ++haystack;
       ++i;
     }

     return (index);
}

int arrayFindSmallest(int * array, int len)
{
    //local declarations
    int i = 1;
    int min = 0;
    int index = 0;
    
   //executables
   
   min = *array;
   array = array + 1;

   for(i = 1; i < len; ++i)
     {
       if(*array < min)
        {
          index = i;
          
        }
       array++;
     }
    
   return (index);
          
}

size_t my_strlen(const char * str)
{
    //local declarations
    int count = 0;
    
   //executables
   while (*str != '\0')
   {
     count++;
     str++;
   }
   return (count);
}

char * my_strchr(const char * str, int ch)
{
    
     char *ret = NULL;
     
    //executables
    while (*str != '\0')
    {
      if (*str ==  ch)
       {
         ret = str;
         return (ret);
      }
      
   
     ++str;
    }
    
      if(*str == ch)		
	{
          ret = str;
	}
    
    return (ret);
    
}

char * my_strstr(const char * haystack, const char * needle)
{
    char *index = NULL;
    int a = 0;
    int b = 1;
    int c = 0;
    if (*needle == '\0')
    {
       return haystack;
     }

    else
    {
       while(*haystack != '\0')
       {
          while((*needle != '\0') && (b == 1))
            {
               if(haystack[a+c]!=needle[c])
		{			
		  b = 0;
		}

                needle++;
                c++;
           }
      
          if(b == 1)		
           {
		 index = haystack;
           }				
		++a;
                ++haystack;
	}
      }
	return index;	
                      
      
}

char * my_strcpy(char * dest, const char * src)
{
    //executables
    
    
      while(*src != '\0')
      {
        *dest = *src;
        ++src;
        ++dest;
      }
    
     *dest = '\0';
     
   return ((char*)dest); 
}

char * my_strcat(char * dest, const char * src)
{  
   //executables
   
    while(*dest != '\0')
     {
       dest++;
     }


   while(*src != '\0')
      {
        *dest = *src;
        src++;
        dest++;
      }
    
    *dest = '\0';
   
     return ((char*)dest);
    
}

int my_isspace(int ch)
{
     
    int counter = 0;
    //executables
     if (ch == (int)' ' || ch == (int)'\f'|| ch == (int)'\n' || ch == (int)'\r' || ch == (int)'\t' || ch == (int)'\v')
     {
       counter =  1;
     }
    else
    {
    counter =  0;
    }
    return counter;
}

int my_atoi(const char * str)
{
    //local declarations
    int ret = 0;
    int index = 0;
    //executables
   while(*str != '\0')
   {
     str++;

   }
   
   if(*str == '-')
   {

      ++str;
      index = 1;
   }

  while (('0' <= *str) && ('9' >= *str))
  {
     ret = ret * 10;
     ret = ret + (*str - '0');
     ++str;
  }
  if (1 == index)
  {
     return(-ret);
   }
  else
  {
    return (ret);
  }

}

