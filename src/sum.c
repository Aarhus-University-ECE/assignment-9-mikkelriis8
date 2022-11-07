#include "sum.h"

int sum(int a[], int n)
{
    /* precondition */
    assert(n >= 0);

    /* postcondition */
    if(n > 0) {
        return a[n - 1] + sum(a, n - 1);
    } else {
        return 0;
    }

    return 0;
}


