#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void test_voidList()
{
    List *list = initList(sizeof(int));
    assert(voidList(list));
    destroyList(list);
    printf("test_voidList successful\n");
}

void test_resetList()
{
    List *list = initList(sizeof(int));
    int a = 42;
    addDataList(list, &a, 0);
    resetList(list);
    assert(voidList(list));
    destroyList(list);
    printf("test_resetList successful\n");
}

void test_readDataList()
{
    List *list = initList(sizeof(int));
    int a = 42;
    int b = 0;

    addDataList(list, &a, 0);
    b = *((int *)(readDataList(list, 0)));
    assert(b == 42 && !voidList(list));
    destroyList(list);
    printf("test_readDataList successful\n");
}

void test_removeDataList()
{
    List *list = initList(sizeof(int));
    int a = 42;

    addDataList(list, &a, 0);
    removeDataList(list, 0);
    assert(voidList(list));
    destroyList(list);
    printf("test_removeDataList successful\n");
}

int main(int argc, char *argv[])
{
    test_voidList();
    test_readDataList();
    test_removeDataList();
    return EXIT_SUCCESS;
}
