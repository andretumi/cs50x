#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //asking the user for pyramid height between 1 to 8
    int pyramid_height;
    do
    {
        pyramid_height = get_int("Pyramid height: ");
    }
    while (pyramid_height < 1 || pyramid_height > 8);

    for (int i = 1; i <= pyramid_height; i++)
    {
        //printing the spaces before the hashes
        for (int j = 0; j < pyramid_height - i; j++)
        {
            printf(" ");
        }
        //printing the hashes of the left
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        //printing the spaces of the middle
        printf("  ");
        //printing the hashes of the right
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        //jumping to the next line to print the next lower step of the pyramid
        printf("\n");
    }

    return 0;
}