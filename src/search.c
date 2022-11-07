#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x)
{
    /* precondition */
    assert(n >= 0);

    /* postcondition */
    if(n > 0 && a[n - 1] == x) {
        return true;
    } else if(n > 0 && a[n - 1] != x) {
        return search(a, n - 1, x);
    } else {
        return false;
    }

    return 0;
}


