/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<stdio.h>
#include<ctype.h>
char removeSpaces(char *str){
		int x, i=0;
	
		if (str == 0 || str[0] == '\0')
			return '\0';
	
		while (str[i] != '\0')
		{
			while (isspace(str[i]))
			{
				for (x = i; str[x] != '\0'; x++)
					str[x] = str[x + 1];
				i = -1;
			}
			i++;
		}
		return '\0';
}