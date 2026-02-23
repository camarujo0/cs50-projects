#include <stdio.h>

int main(void)
{

    //  Numbers to sum

    int M = 0;
    int N = 0;

    //  While loop is only for the beecrowd validation system
    
    while (scanf("%d %d", &M, &N)!= EOF)
    {
        long long resM = 1;
        long long resN = 1;



        //  Gets the factorial value of M

        if (0 <= M && M <= 20)
        {
            for (long i = 1; i <= M; i++)
            {
                resM *= i;
            }
        }
        else
        {
            return 0;
        }

        //  Gets the factorial value of N

        if (0 <= N && N <= 20)
        {
            for (long i = 1; i <= N; i++)
            {
                resN *= i;
            }
        }
        else
        {
            return 0;
        }

        printf("%lld \n", resM + resN);
    }
    return 0;
}
