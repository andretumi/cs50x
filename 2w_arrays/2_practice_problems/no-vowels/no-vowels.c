// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string text);


int main(int argc, string argv[])
{
    //ends the program and tells the user the correct usage of the program("Usage: ./no-vowels word")
    if (argc <= 1)
    {
        printf("Usage: ./no-vowels word \n");
        return 1;
    }
    //prints the inputed word but numbers instead of vowels, except for vowel u
    else
    {
        for (int j = 1; j < argc; j++)
        {
            printf("%s ", replace(argv[j]));
        }
        printf("\n");
        return 0;
    }
}

string replace(string text)
{
    //loop that iterates through the word
    for (int i = 0; text[i] != '\0'; i++)
    {
        //replaces the vowels for letters, exept for the u
        switch (text[i])
        {
            case 'a':
                text[i] = '6';
                break;
            case 'e':
                text[i] = '3';
                break;
            case 'i':
                text[i] = '1';
                break;
            case 'o':
                text[i] = '0';
                break;
            default:
                break;
        }
    }
    //returns the word to be printed
    return text;
}
