#include <cs50.h>
#include <stdio.h>

void print_base(int blocks);

int main(void)
{
    //  Prompt user for input
    int Height;
    do
    {
        Height = get_int("Height: ");
    }
    while (Height < 1 || Height > 8);

    //  Creates the pyramid
    for (int i = 0; i < Height; i++)

    //  Creates the blank spaces first, then the pyramid

    {
        for (int j = 0; j < Height - (i + 1); j++)
        {
            printf(" ");
        }
        print_base(i + 1);

        printf(" ");
        printf(" ");

        print_base(i + 1);

        printf("\n");
    }
}

//  Defines the base of the triangle

void print_base(int blocks)
{
    for (int i = 0; i < blocks; i++)
    {
        printf("#");
    }
}
