// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

//declaring function that will validate if the password meets the requirements
bool valid(string password);

int main(void)
{
    //getting password from the user
    string password = get_string("Enter your password: ");

    //sending answer to the user
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

//function recieves the user's password as a parameter
bool valid(string password)
{
    //variables that will define if the password meets each of the requierments
    bool hasUpper = false;
    bool hasLower = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    //loop that iterates through each of the characters of the password, untill it finds the end of it ('\0')
    for (int i = 0; password[i] != '\0'; i++)
    {
        //validating if the password has upper case data type in the letter
        if (isupper(password[i]))
        {
            //changing the value of hasUpper to true, cuz it contains at least an upper cased letter (same applies for the following)
            hasUpper = true;
        }
        //validating if the password has lower case data type in the letter
        else if (islower(password[i]))
        {
            hasLower = true;
        }
        //validating if the password has number data type in the letter
        else if (isdigit(password[i]))
        {
            hasNumber = true;
        }
        //validating if the password has symbol data type in the letter
        else if (ispunct(password[i]))
        {
            hasSymbol = true;
        }
    }

    //once the condition (if / else if) finished and the values of the bool variables are updated (eg: hasNumber)
    //the following conditional will return true ("valid")if the password meets all the requirements or else will return false ("needs at least ...")
    if (hasUpper && hasLower && hasNumber && hasSymbol)
    {
    return true;
    }

    return false;
}
