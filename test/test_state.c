#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "state.h"

enum {
    ACCEPT, REFUSE, POTENTIAL
};

void test_getState(void)
{
    State *state = initState(5);
    resetState(state, POTENTIAL);
    setState(state, REFUSE, 2);

    assert(getState(state, 2) == REFUSE);

    destroyState(state);
    printf("test_getState successful\n");
}


void test_analyseState(void)
{
    State *state = initState(5);
    resetState(state, POTENTIAL);
    setState(state, REFUSE, 2);

    assert(analyseState(state, ACCEPT) == -1);
    assert(analyseState(state, POTENTIAL) == 0);
    assert(analyseState(state, REFUSE) == 2);

    destroyState(state);
    printf("test_analyseState successful\n");
}

int main(int argc, char *argv[])
{
    test_getState();
    test_analyseState();
    return EXIT_SUCCESS;
}
