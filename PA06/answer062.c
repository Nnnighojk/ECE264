#include<stdio.h>
//#include<string.h>
#include "answer06.h"
//#include<math.h>
#include <stdlib.h>


#define T 1
#define F 0

SparseNode * SparseNode_create(int index, int value)
{
   if (value == 0)
   return NULL;

   SparseNode * set = malloc(sizeof(SparseNode));
   set->index = index;
   set->value = value;
   set->right = NULL;
   set->left = NULL;
   return set;
}


SparseNode * SparseArray_insert(SparseNode * array, int index, int value)
{
  if(array == NULL);
  {
    return SparseNode_create(index, value);
  }

  if (array->index == index)
  {
    array->value = value;
  }
  
  else if (array->index > index)
  {
    array->left = SparseArray_insert(array->left, index, value);
  }

  else if (array->index < index)
  {
   array->right = SparseArray_insert(array->right, index, value);
  }

  return array;

}

SparseNode * SparseArray_build(int * indices, int * values, int length)
{
  SparseNode *start = NULL;
  int ser = 0;
  for (ser = 0; ser < length; ++ser)
  {
 
   start = SparseArray_insert(start, indices[ser], values[ser]);
  }

return start;

}

void SparseArray_destroy(SparseNode * array)
{
  if(array == NULL)
  {
    return;
  }

  SparseArray_destroy(array->left);
  SparseArray_destroy(array->right);
  free(array);
  array = NULL;
}


int SparseArray_getMin(SparseNode * array)
{
  
  if(array->left == NULL)
  {
    return array->index;
  }
  
  return SparseArray_getMin(array->left);

}

int SparseArray_getMax(SparseNode * array)
{

  if(array->right == NULL)
  {
    return array->index;
  }
  
  return SparseArray_getMax(array->right);

}



SparseNode * SparseArray_getNode(SparseNode * array, int index)
{
  if(array == NULL)
  { 
    return NULL;
  }

  if(array->index == index)
  {
     return array;
  }
  
  if(array->index > index)
  {
    return SparseArray_getNode(array->left, index);
  }
  
  return SparseArray_getNode(array->right, index);
}

SparseNode * SparseArray_remove(SparseNode * array, int index)
{
  if(array == NULL)  
  {
     return NULL;
  }

  if (index < (array -> index))
  {
    array -> left = SparseArray_remove(array->left, index);
    return array;
  }

  if (index > (array -> index))
  {
    array -> right = SparseArray_remove(array->right, index);
    return array;
  }

  if((array -> left) == NULL)
  {
    if((array -> right) == NULL)  
    {
       free(array);
       return NULL;
    }
    else  
    {
      SparseNode * start = array -> right;  
      free(array);
      return start;
    }
  }
  if((array -> right) == NULL)  
  {
    SparseNode * start = array -> left;  
    free(array);
    return start;
  }


  SparseNode * next = (array -> right);  
  
  while((next -> left) != NULL)  
  next = (next -> left);
  
  int value = (array -> value);
  (array -> index) = (next -> index);
  (array -> value) = (next -> value);
  (next -> index) = index;
  (next -> value) = value;
  (array -> right) = SparseArray_remove(array -> right, index);  
  return array;
}

SparseNode * SparseArray_copy(SparseNode * array)
{
  if(array == NULL)
  {
    return NULL;
  }
  
  SparseNode * set = NULL;
  set = malloc(sizeof(SparseNode));
  set->index = array->index;
  set->value = array->value;
  set->right = SparseArray_copy(array->right);
  set->left = SparseArray_copy(array->left);
  return set;
}

void help_merge(SparseNode *start, SparseNode *array)
{
   if(array==NULL)
   {
     return;
   }	

   help_merge(start, array->left);
	
	
   SparseNode *ptr = SparseArray_getNode(start, array->index);
   if(ptr == NULL)	
   {
     SparseArray_insert(start, array->index, array->value);
     ptr->value += array->value;
   }
   if(ptr->value==0)
   {
    SparseArray_remove(start, ptr->index);	
   }	
   
   help_merge(start, array->right);
	
   return;
}

SparseNode *SparseArray_merge(SparseNode *array1, SparseNode *array2)
{
   if(array1==NULL && array2==NULL)
   {
      return NULL;
   }
	
   else if(array1==NULL)
   {		
     return SparseArray_copy(array2);
   }
   
   else if(array2 == NULL)
   {		
     return SparseArray_copy(array1);
   }
	
   SparseNode *start = SparseArray_copy(array1);
   help_merge(start, array2);
	
   return start;
}

