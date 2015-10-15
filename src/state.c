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
    return state;
}

void resetState(State *state, int value)
{
    for (int i = 0; i < state->nbState; i++)
	state->buffer[i] = value;
}

void setState(State *state, int value, int id)
{
    if (id < 0 || id >= state->nbState)
	fprintf(stderr, "Error: incorrect state identifier.\n");
    else
	state->buffer[id] = value;
}

int getState(State *state, int id)
{
    return state->buffer[id];
}

int analyseState(State *state, int value)
{
    for (int i = 0; i < state->nbState; i++)
	if (state->buffer[i] == value)
	    return i;
    return -1;
}	

void destroyState(State *state)
{
    free(state->buffer);
    free(state);
}
