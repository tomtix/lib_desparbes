#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "state.h"

void test_setRefuseState()
{
    State *state = initState(5);
    setRefuseState(state, 2);

    assert(analyseState(state) == -1);

    setRefuseState(state, 0);
    setRefuseState(state, 1);
    setRefuseState(state, 3);
    
    assert(analyseState(state) == 4);
    destroyState(state);
}

void test_analyseState()
{
    State *state = initState(5);
    assert(analyseState(state) == -1);
    destroyState(state);
}

int main(int argc, char *argv[])
{
    test_setRefuseState();
    test_analyseState();
    return EXIT_SUCCESS;
}
