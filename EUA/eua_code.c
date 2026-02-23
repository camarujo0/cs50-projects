#include <stdio.h>

int main(void)
{
    int rows = 7; // 6 main rows + 1 final line
    int i, j;

    // initial counts
    int forward = 12; // number of '/'
    int back = 0;     // number of '\'

    for (i = 0; i < rows; i++)
    {
        int leftStars = (i < 6) ? (6 - i) : 0; // 6→1 stars, then 0 for last line
        int before = i + 1;                    // spaces before middle
        int after = (i < 6) ? before : 2;      // last line has small trailing gap

        // left pyramid
        for (j = 0; j < leftStars; j++)
            putchar('*');

        // spaces before slashes
        for (j = 0; j < before; j++)
            putchar(' ');

        // forward slashes
        for (j = 0; j < forward; j++)
            putchar('/');

        // backslashes
        for (j = 0; j < back; j++)
            putchar('\\');

        // spaces after middle
        for (j = 0; j < after; j++)
            putchar(' ');

        // right pyramid (only for first 6 rows)
        for (j = 0; j < leftStars; j++)
            putchar('*');

        putchar('\n');

        // update counts for next row
        if (i < 5)
        {
            forward -= 2;
            back += 2;
        }
        else if (i == 5)
        {
            // final full backslash line setup
            forward = 0;
            back = 12;
        }
    }
}
