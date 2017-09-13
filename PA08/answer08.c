#include<stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include "answer08.h"
#include<math.h>

uint128 alphaTou128(const char * str)
{
  if(str==NULL)	
  {
   return 0;
  }
  uint128 result = 0;
  int ptr = 0;
  while(str[ptr]!='\0')	
  {
    if(str[ptr]=='-')
    {
      return 0;
    }
    if(str[ptr] >= '0' && str[ptr] <= '9')
    {
      result = result*10 + (str[ptr] - '0');
      ++ptr;
    }
  }
 return result;
}

char * u128ToString(uint128 value)
{
  char * ans;
  uint128 res = value;
  int i = 0;

  if ( value == 0 )
  {
    ans = malloc ( sizeof ( char ) + 1 );
    ans[0] = (char)48;
    ans[1] = '\0';

    return ans;
  }

  while ( res!= 0 )
  {
    res /= 10;
    i++;
  }

  ans = malloc ( sizeof( char ) * i + 1 );

  ans[i] = '\0';
  i--;
	
  while ( !(i < 0 ) )
  {
    ans[i] = (char) ( value % 10 + 48 );
    value = value / 10; 
    i--;
   }

  return ans;
}

typedef struct
{
  uint128 low;
  uint128 high;
  uint128 value;
  int *flag;
}ThreadData;

void * thread_fn(void *arg)
{
 ThreadData *da = (ThreadData *)arg;
 uint128 ans = da->low;
 while(ans <= da->high)
 {
  if(da->value % ans == 0)
  {
   *(da->flag) = FALSE;
  }
   ans = ans + 2;
 }
 
}


int primalityTestParallel(uint128 value, int n_threads)
{

  if(value <= 1)
  {
    return FALSE;
  }
  else if(value == 2)
  {
    return TRUE;
  }
  else if( (value % 10) % 2 == 0 )
  {
   return FALSE;
  }
  else if( value == 3)
  {
   return TRUE;
  }
		
  int result = TRUE;
  pthread_t *th = malloc(sizeof(pthread_t)*n_threads);
  ThreadData *td = malloc(sizeof(ThreadData)*n_threads);
	
  int i;
  uint128 u_l = sqrt(value)/n_threads;
  if(u_l%2==1)
  u_l++;
  for(i = 0; i < n_threads; ++i)	
  {
    td[i].flag  = &result;
    td[i].value = value;
    td[i].low   = 3 + i*(u_l);
    td[i].high  = td[i].low + (u_l);
  }
	
  for(i = 0; i < n_threads; ++i)	
  pthread_create( &th[i], NULL, &thread_fn, &td[i] );
	
  for(i = 0; i < n_threads; ++i)	
  pthread_join(th[i], NULL);
	
  free(td);		
  free(th);	
	
  return result;
}


