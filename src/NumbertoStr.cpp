/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<math.h>

int pow(int n, int d)
{
	if (d == 0)
		return 1;
	return n*pow(n, d - 1);
}

void reverse(char *str, int len, bool flag)
{
	int i = 0, j = len - 1, temp;
	if (flag)
		i++;
	while (i<j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}
}

int intToStr(int x, char str[], int d)
{
	bool flag = false;
	int i = 0;
	if (x<0)
	{
		str[i] = '-';
		i++;
		x = x*-1;
		flag = true;
	}

	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	
	while (i < d)
		str[i++] = '0';

	reverse(str, i, flag);
	str[i] = '\0';
	return i;
}

void number_to_str(float n, char *res, int afterpoint)
{

	int ipart = (int)n;
	float fpart = n - (float)ipart;
	if (n<0)
		fpart = fpart*-1;
	
	int i = intToStr(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.'; 
		fpart = fpart * pow(10, afterpoint);

		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}
