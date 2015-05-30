#include <stdio.h>
#include <stdlib.h>

#include "state.h"

typedef struct State {
    int *buffer;
    int nbState;
}State;

State *initState(int nbState)
{
    State *state = malloc(sizeof(State));
    state->buffer = malloc(nbState * sizeof(int));
    state->nbState = nbState;
    resetState(state);
    return state;
}

void resetState(State *state)
{
    for (int i = 0; i < state->nbState; i++)
	state->buffer[i] = 1;
}

void setRefuseState(State *state, int id)
{
    if (id < 0 || id >= state->nbState)
	fprintf(stderr, "Error: incorrect state identifier.\n");
    else
	state->buffer[id] = 0;
}

int analyseState(State *state)
{
    int i = 0;

    while (i < state->nbState && !state->buffer[i])
	i++;

    if (i >= state->nbState)
	return -1;

    int firstMatch = i;

    for (i++; i < state->nbState; i++)
	if (state->buffer[i])
	    return -1;
    return firstMatch;
}	

void destroyState(State *state)
{
    free(state->buffer);
    free(state);
}
