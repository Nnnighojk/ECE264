#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This includes the /declaratinos/ of the functions that you write
// in this assignment. Including the declarations allows you to use
// the functions in this file.

#include "answer02.h"

int main(int argc, char * * argv)
{
    printf("Welcome to ECE264, we are working on PA01.\n"
	   "\n"
	   "You are encouraged to edit this file in order to test\n"
	   "the behavior of the functions you write in answer02.c\n"
	   "\n"
	   "This file will not be marked, and should not be\n"
	   "submitted.\n"
	   "\n"
	   "Don't forget to post questions on blackboard, and ask\n"
	   "the TAs and your classmates for help.\n"
	   "\n");
    
	// -- my_strcat_ex
	
	int n = 7;	
	char *s1 = malloc(n*sizeof(char));	
	
	//char *s1; ---> Doing this would make make s1 also of type const char and hence we would not be able to modify it in the functions
	strcpy(s1, "abcd e");   //
	const char *s2 = "7757";
	printf("\n%s\n", strcat_ex(&s1, &n, s2)); 
	free(s1);

	// -- explode
	int len = 3;	
	char * * strArr = explode("The\nTuring Test", " \t\v\n\r\f", &len);
	int i;	
	for(i = 0; i < len; i++)
	{
		printf("\n%s\n", strArr[i]);
	}
	free(strArr); 

	// -- implode
	int len1 = 4;
 	char * * strArr1 = explode("hi how are you", " ", &len1);
 	char * str = implode(strArr1, len1, ", ");
 	printf("\n%s\n", str);
	free(strArr1);
	free(str);

	// -- sortStringArray
	int slen = 16;
	char * * strArr2 = explode("lady beatle brew", " ", &slen);
	//int i;
	sortStringArray(strArr2, slen);
	char * str2 = implode(strArr2, slen, " ");
	printf("\n\n%s\n", str2); 
	free(strArr2);

	// -- sortStringcharacters
	char * s11 = strdup(" aaabaaa  ");
	printf("\n\nOriginal string: %s\n", s11);
	sortStringCharacters(s11); 	
	printf("\n\nSorted String: %s\n", s11);

	// -- destroy
	int plen;
	const char * abe = "Give me six hours to chop down a tree and I will spend\n"
                    		"the first four sharpening the axe.";
	char * * pstrArr = explode(abe, "\n ", &plen);
	destroyStringArray(pstrArr, plen); // cleans memory -- no memory leaks
	destroyStringArray(NULL, 0); // does nothing, does not crash.
	
	
	return EXIT_SUCCESS;
	
}


