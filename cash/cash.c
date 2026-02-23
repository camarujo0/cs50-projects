#include <cs50.h>
#include <stdio.h>

void change(float value)
{
    enum { moeda25, moeda10, moeda5, moeda1 };

    int change[4];

    //  Checks the minimum amount of coins needed

    change[moeda25] = (int) value / 25;
    value -= (change[moeda25] * 25);

    change[moeda10] = (int) value / 10;
    value -= (change[moeda10] * 10);

    change[moeda5] = (int) value / 5;
    value -= (change[moeda5] * 5);

    change[moeda1] = (int) value;
    value -= (change[moeda1]);

    int change_owed = (change[moeda25]) + (change[moeda10]) + (change[moeda5]) + (change[moeda1]);

    printf("%d \n", change_owed);
}

int main(void)
{
    float value;

    //  Prompts user the changed owed and checks if it's valid number

    do
    {
        value = get_float("Change owed: ");
    }
    while (value < 0);

    change(value);
}
