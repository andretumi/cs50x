#include <cs50.h>
#include <stdio.h>

int calculate(int cent, int coinValue);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    } while (cents < 0);

    int quarters = calculate(cents, 25);
    cents -= (quarters * 25);

    int dimes = calculate(cents, 10);
    cents -= (dimes * 10);

    int nickels = calculate(cents, 5);
    cents -= (nickels * 5);

    int pennies = calculate(cents, 1);
    cents -= (pennies * 1);

    int totalCoins = quarters + dimes + nickels + pennies;

    printf("%i\n", totalCoins);
}

int calculate(int cent, int coinValue)
{
    int coin = 0;
    while (cent >= coinValue)
    {
        coin++;
        cent -= coinValue;
    }
    return coin;
}
