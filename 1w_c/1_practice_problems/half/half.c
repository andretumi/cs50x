// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, float tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    float tip_percent = get_int("Tip percent: ");

    half(bill_amount, tax_percent, tip_percent);

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

float half(float bill, float tax, float tip)
{
    int half = 2;
    float total_tax = bill * (tax / 100);
    float total_tip = bill * (tip / 100);
    float gross_total = total_tax + total_tip + bill;

    return gross_total / half;
}
