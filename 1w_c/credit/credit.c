#include <cs50.h>
#include <stdio.h>
#include <string.h>

string validCard(unsigned long cardNumber);

int main(void)
{
    unsigned long cardInput = get_long("Number: ");
    printf("%s\n", validCard(cardInput));
    return 0;
}

string validCard(unsigned long cardNumber)
{
    int length = strlen(cardNumber);
    if (13 <= length <= 16)
    {
        int digitsMultipliedByTwo = 0;
        int spareDigits = 0;
        for (int i = 1; i <= length; i = i + 2)
        {
            digitsMultipliedByTwo += cardNumber[i] * 2;
        }
        for (int i = 0; i <= length; i = i + 2)
        {
            spareDigits += cardNumber[i - 1];
        }
        string sum = digitsMultipliedByTwo + spareDigits;

        if (strncmp(sum, "0", 1) == 0)
        {
            if (strncmp(cardNumber, "34", 2) == 0 || strncmp(cardNumber, "37", 2) == 0)
            {
                return "AMEX\n";
            }
            if (strncmp(cardNumber, "51", 2) == 0 || strncmp(cardNumber, "52", 2) == 0 || strncmp(cardNumber, "53", 2) == 0 || strncmp(cardNumber, "54", 2) == 0 || strncmp(cardNumber, "55", 2 == 0))
            {
                return "MASTERCARD\n";
            }
            // if (strcmp(cardNumber, "4", 1) == 0)
            // {
            //     return "VISA\n";
            // }
        }
        else
        {
            return "INVALID\n";
        }
    }
    else
    {
        return "INVALID\n";
    }
}

// -----INITIAL VERSION THAT WORKED PARTIALLY
// #include <cs50.h>
// #include <stdio.h>

// int is_valid_card(long card_number)
// {
//     int sum = 0;
//     int digit_count = 0;
//     int multiply = 0;

//     while (card_number > 0)
//     {
//         int digit = card_number % 10;
//         card_number /= 10;
//         digit_count++;

//         if (multiply)
//         {
//             digit *= 2;
//             while (digit > 0)
//             {
//                 sum += digit % 10;
//                 digit /= 10;
//             }
//         }
//         else
//         {
//             sum += digit;
//         }

//         multiply = !multiply;
//     }

//     return (sum % 10 == 0 && digit_count >= 13 && digit_count <= 16);
// }

// int main()
// {
//     long card_number = get_long("Type the card number: ");
//     int valid = is_valid_card(card_number);

//     if (valid)
//     {
//         int first_two_digits = card_number / 10;

//         switch (first_two_digits)
//         {
//         case 34:
//         case 37:
//             printf("AMEX\n");
//             break;
//         case 51:
//         case 52:
//         case 53:
//         case 54:
//         case 55:
//             printf("MASTERCARD\n");
//             break;
//         default:
//             if (card_number / 10000000000000 == 4)
//             {
//                 printf("VISA\n");
//             }
//             else
//             {
//                 printf("Card number is valid.\n");
//             }
//             break;
//         }
//     }
//     else
//     {
//         printf("INVALID\n");
//     }

//     return 0;
// }
