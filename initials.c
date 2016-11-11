#include <stdio.h>
#include <cs50.h> // to use GetString method
#include <string.h> // to check string length
#include <ctype.h> // to identify and convert lowercase character to uppercase character


int main(void)
{
    string s = GetString();
    
    if ( islower(s[0])) // if-else statement to print first uppercase initial.
    {
        printf("%c", toupper(s[0]));
    }
    else 
    {
        printf("%c", s[0]);
    }
    

   for(int i=1 , n = strlen(s) ; i <n ; i++) // for loop, to scan all the spaces in between user input and print upper case initials each time.
   {
       if (s[i] == ' ')
       {
           if ( islower(s[i+1]))
           {
                printf("%c", toupper(s[i+1]));
            }
            else
            {
                printf("%c", s[i+1]);
            }
       }
       
   }
    printf("\n");
}

