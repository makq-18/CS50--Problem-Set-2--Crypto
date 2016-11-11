#include <stdio.h>
#include <ctype.h>
#include <cs50.h>       // to use GetString method.
#include <string.h>     // to find length of the string.

int main(int argc , string argv[])      // the parameters inside main method are to read key value and number of arguments.
{
   if ( argc < 2 || argc > 2)       // to verify that user enter only one key value with file name.
   {
       printf("Error! Please enter the key in command-line prompt.\n");
       
       return 1;    // to signify error and stop main method.
   }
   else
   {
       string s = GetString();
       int key = atoi(argv[1]); // convert key value from string to integer.
       for (int i = 0 , n = strlen(s) ; i < n ; i++)
       {
           
           if(s[i] == ' ') // to encrypt space as space only.
           {
               printf(" ");
           }
           else if(isupper(s[i])) // to encrypt uppercase letters
           {
                int con = (int) s[i];
                int icipher = (con + key); // icipher variable holds encrypted character as an integer.
                if(icipher <=90 && icipher >= 65) // if encrypted character value does not exceeds range of upper case letter(s).
                {
                printf("%c", (char) icipher);
                }
                else if( icipher > 90) // if encrypted character value exceeds range of upper case letter(s).
                {
                    do // if encrypted cipher value is outside the range of letter(s).
                    {
                        icipher = (icipher % 90) + 64;
                    }while (icipher > 90);
                printf("%c", (char) icipher);
                
                }
           }   
           else if(islower(s[i])) // to encrypt lower case letter(s).
           {
               int con = (int) s[i];
               int icipher = (con + key);
               if(icipher <=122 && icipher >= 97)
                {
                    printf("%c", (char) icipher);
                }
                else if( icipher > 122)
                {
                    do
                    {
                         icipher = (icipher % 122) + 96;
                    }while (icipher > 122);
                printf("%c", (char) icipher);
                
                }
           }
           else 
           {
              printf("%c", s[i]); // to encrypt symbols and special characters as same.
           }
       }  
       printf("\n");
       return 0; // to signigy sucessful execution and stop main method.
   }
}
   