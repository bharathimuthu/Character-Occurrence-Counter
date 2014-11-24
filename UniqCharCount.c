/*
*	Program to count and displays the occurrence count of alphabets contained in a string. 
*	
*	@Author: Bharathi M
*	@Version: 1 19/11/2014
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{	/*Input Text */
    char text[]="The quick brown fox jumps over the lazy dog and the sleeping cat early in the day.";
 
    int TextLen=0;
    int i,j;
    int printed=0;

    TextLen=strlen(text); //Length of input string 
    int count[TextLen]; //Array to store the occurrence count 

	/*Loop to count occurrences*/
    for(i=0;i<TextLen;i++)
    {   
		text[i]=tolower(text[i]);
		if(text[i]>=65 && text[i]<=90 || text[i]>=97 && text[i]<=122)
		{	count[i]=1;
        	for(j=0; j<TextLen;j++)
        	{
				if(i!=j) 
				{   
				if(text[i]==text[j])
				count[i]++;
				}
			}
		}
		else
		{ 
			count[i]=0; //Excluding whitespace and anything not [a-z][A-Z]
		}
      }
	
 	printf("Alphabets and their occurrence counts are as follows\n");
	/* Loop to Display output*/
    for(i=0;i<TextLen;i++)
	{	if(count[i])
		{
			for(j=0;j!=i&&j<i;j++)
			{ 
				if(text[i]==text[j])
				{
				printed=1;
				break;
				}
				else
				printed=0;
			}
			if(!printed)
 	   		printf("%c : %d \n",text[i],count[i]);
	    }
	}
    return(0);   
}
