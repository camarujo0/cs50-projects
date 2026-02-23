#include <stdio.h>
#include <stdbool.h>

bool is_valid(int Mvalid, int Nvalid);
long long factorial_sum (int Mfac, int Nfac);

int main (void)
{
    int N, M;

    printf("Numbers: ");
    scanf("%d %d", &M, &N);

    while (!is_valid(M,N))
    {
        printf("\nThe numbers must be between 0 and 20!\n");
        printf("Numbers:");
        scanf("%d %d", &M, &N);
    }

    printf("Factorial sum of %d and %d is %lld\n", M, N, factorial_sum(M, N));

}

bool is_valid (int Mvalid, int Nvalid)
{
    if ((Mvalid >= 0 && Mvalid <=20) && (Nvalid >=0 && Nvalid <=20))
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long factorial_sum (int m, int n)
{
    long long Mfac = 1;
    long long Nfac = 1;
    long long sum = 0;

    for(int i = 0; i < m; i++)
    {
        Mfac *= (m-i);
    }

    for(int i = 0; i < n; i++)
    {
        Nfac *= (n-i);
    }

    sum = Mfac + Nfac;

    return sum;
}
