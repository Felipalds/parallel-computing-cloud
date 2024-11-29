#include <stdio.h>
#include <omp.h>
#define n 200

int main()
{
    int dot=0;
    int a[n];
    int b[n];


    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        a[i]=1;
        b[i]=1;
    }

    for (int i = 0; i<n;i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    omp_lock_t writelock;
    omp_init_lock(&writelock);

    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        omp_set_lock(&writelock);
        dot += a[i]*b[i];
        omp_unset_lock(&writelock);

    }

    #pragma omp barrier

    printf("Dot: %d \n\n", dot);
    return 0;
}
