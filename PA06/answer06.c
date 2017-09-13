#include "answer06.h"
#include <stdio.h>
#include <stdlib.h>


SparseNode *SparseNode_create(int index, int value)
{
  SparseNode * ptr = malloc(sizeof(SparseNode));
  
  ptr -> index = index;
  ptr -> value = value;
  
  ptr -> left = NULL;
  ptr -> right = NULL;
  
  return ptr;
}



SparseNode * SparseArray_insert ( SparseNode * array, int index, int value )
{
  if(value == 0)  
  {
    return array;
  }
  
  if(array == NULL) 
  {
    return SparseNode_create(index, value); 
  }

  if((array -> index) == index)
    {
      (array -> value) = value;  
      return array;
    }
  
  if((array -> index) > index)
    {
      (array -> left) = SparseArray_insert(array -> left, index, value); 
      return array;
    }
  
  (array -> right) = SparseArray_insert(array -> right, index, value);  
  
  return array;
}


SparseNode *SparseArray_build(int * indicies, int * values, int length)
{
  SparseNode * start = NULL;  
  int ser = 0;
  
  for(ser = 0; ser < length; ser++)
    {
      start = SparseArray_insert(start, indicies[ser], values[ser]);  
    }
  
  return start;
}


void SparseArray_destroy ( SparseNode * array )
{
  if(array == NULL) 
    {
      free(array);
      return;
    }
  
  SparseArray_destroy(array -> left);  
  SparseArray_destroy(array -> right);
  free(array);
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



SparseNode * SparseArray_getNode(SparseNode * array, int index )
{
  if(array == NULL)  
    return NULL;
  
  if((array -> index) == index)  
    {
      return array;
    }
      
  if((array -> index) > index)  
  {
    return SparseArray_getNode(array -> left, index);
  }

  return SparseArray_getNode(array -> right, index);  
}

SparseNode * SparseArray_remove ( SparseNode * array, int index )
{
  if(array==NULL)
  {
    return NULL;
  }
  SparseNode *rmv = SparseArray_getNode(array, index);
  if(rmv == NULL)
  {
    return NULL;
   }
   if(rmv->right==NULL && rmv->left==NULL)
   {
      free(rmv);
      return array;
   }
   if(rmv->right == NULL)
   {
     SparseNode *temp = rmv->left;
     rmv->left = temp->left;
     rmv->right = temp->right;
     rmv->index = temp->index;
     rmv->value = temp->value;
     free(temp);
     return array;
   }
  if(rmv->left == NULL)
  {
    SparseNode *temp = rmv->right;
    rmv->left = temp->left;
    rmv->right = temp->right;
    rmv->index = temp->index;
    rmv->value = temp->value;
    free(temp);
    return array;
   }
	
  SparseNode *n = NULL;
  n = SparseArray_getNode(n, SparseArray_getMin(rmv->right));
  rmv->index = n->index;
  rmv->value = n->value;
  return SparseArray_remove(n, n->index);
}


SparseNode * SparseArray_copy(SparseNode * array)
{
  if(array == NULL)  
    return NULL;
  
  SparseNode * dupli = NULL;
  
  dupli = SparseArray_insert(dupli, array -> index, array -> value);
  
  (dupli -> left) = SparseArray_copy(array -> left);
  (dupli -> right) = SparseArray_copy(array -> right);
  
  return dupli;
}


SparseNode * Merge2( SparseNode * array, int index, int value )
{
  if(value == 0) 
  {
   return array;
  }
  
  if(array == NULL)  
  {
   return SparseNode_create(index, value);  
  }

  if((array -> index) == index)
    {
      (array -> value) += value;  
      return array;
    }
  
  if((array -> index) > index)
    {
      (array -> left) = Merge2(array -> left, index, value);  
      return array;
    }
  
  (array -> right) = Merge2(array -> right, index, value);  
  
  return array;
}

SparseNode * merge1(SparseNode * dupli, SparseNode * array)
{
  if(array == NULL)
    return dupli;
  
  dupli = Merge2(dupli, array -> index, array -> value);
  dupli = merge1(dupli, array -> left);
  dupli = merge1(dupli, array -> right);
  return dupli;
}

SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2)
{
  int count;
  int a;
  int b;
  
  if(array_1 == NULL)
  {
    return array_2;
  }

  if(array_2 == NULL)
  {
    return array_1;
  }

  SparseNode * dupli = SparseArray_copy(array_1);  
  dupli = merge1(dupli, array_2);  
  
  a = SparseArray_getMin(dupli);
  b = SparseArray_getMax(dupli);
  
  for(count = a; count <= b; count++)
    {
      if (SparseArray_getNode(dupli, count) && (SparseArray_getNode(dupli, count) -> value == 0))
      dupli = SparseArray_remove(dupli, count);
    }
  
  return dupli;
}



