#include <stdio.h>
#include <cs50.h>  
#include <ctype.h> // to check upper case and lower case letters.
#include <string.h> // to find string length.

int main(int argc , string argv[])
{
    if(argc > 2 || argc < 2) // if user insert less or more than 2 input commands.
    {
        printf("Error!");
        return 1; // stop main function with error message. 
    }
    string k = argv[1]; // string variable to store key value
    
    for ( int c = 0 , key_length = strlen(argv[1]); c<key_length; c++) // for loop to verify if key contains all alphabets. 
    {
        if(!(k[c] >= 'a' && k[c] <= 'z') && !(k[c] >= 'A' && k[c] <='Z'))
        {
            printf("Please enter valid key between 'A -Z' or 'a-z'\n");
            return 1; // stop main function with error message
        }
    }
    for(  int y = 0 , key_converter = strlen(argv[1]) ; y< key_converter ; y++) // for loop to convert all upper case alphabets to lower case alphabets of key
    {
        k[y] = tolower(k[y]);
    }

    
    string s = GetString();
    int key_length = strlen(k); // variable for length of the key
    
    for (int i = 0 , j =0 , n = strlen(s) ; i < n ; i++ , j++) // for loop repeating for length of plain text
    {
        
        
       
       if ( (islower(s[i])) || (isupper(s[i])))  // if loop for only upper case and lower case alphabets
        {
            if((j% key_length) ==0) // to repeat key alphabets
            {
                j=0;
            }
            if (islower(s[i])) // if loop for lower case letters
            {
                int icipher = ((int)s[i]) + ((int) k[j] - 97); // encryption formula for lower case letters and adding key value between 0 - 26 only.
            
                if(icipher >= 97 && icipher <= 122)
                {
                    printf("%c", (char) icipher); // print cipher value if it does not exceed lower case letter range
                }
                else     // to convert cipher value into range of lower case letter.
                {
                    do
                    {
                        icipher = icipher % 122;
                    }while(icipher > 122);
                    
                printf("%c", (char) icipher + 96); 
                }
            
            }
        
            else if (isupper(s[i])) // else if loop for upper case letters.
            {
                int con = (int) s[i] + ((int) k[j] - (int) 'a');
                if(con > 90)
                {
                    do
                    {
                        con = con % 90;
                    }while (con > 90);
                    printf("%c", (char) con + 64);
                }
                else
                {
                    printf("%c", (char) con);
                }
            }
            
           
        }
         else // else condition to print all non-alphabets from the plain text
        {
            printf("%c", s[i]);
            j = j-1; // to exclude key counter for non-alphabtets
            
        }
        

    }
    
    printf("\n");
    return 0; // stop main function after successfull execution
}