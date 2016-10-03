#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "search.h"

void test_intSearch()
{
    int t[5] = {1, 3, 4, 5, 7};
    int a[4] = {1, 7, 3, 2};
    assert(search(t, sizeof(int), 5, &a[0], intcmp) == 0);
    assert(search(t, sizeof(int), 5, &a[1], intcmp) == 4);
    assert(search(t, sizeof(int), 5, &a[2], intcmp) == 1);
    assert(search(t, sizeof(int), 5, &a[3], intcmp) == -1);
    printf("test_intSearch successful\n");
}

void test_strSearch()
{
    char t[7][9]= {"dimanche", "jeudi", "mardi", "mercredi",
                   "lundi", "samedi", "vendredi"};
    assert(search(t, 9, 7, "dimanche", (compare_t) strcmp) == 0);
    assert(search(t, 9, 7, "vendredi", (compare_t) strcmp) == 6);
    assert(search(t, 9, 7, "jeudi", (compare_t) strcmp) == 1);
    assert(search(t, 9, 7, "manchedi", (compare_t) strcmp) == -1);
    printf("test_strSearch successful\n");
}

int main(int argc, char *argv[])
{
    test_intSearch();
    test_strSearch();
    return EXIT_SUCCESS;
}

