#ifndef STATE_H
#define STATE_H

typedef struct State State;

State *initState(int nbState);
void resetState(State *state, int value);
void setState(State *state, int value, int id);
int getState(State *state, int id);
int analyseState(State *state, int value);
void destroyState(State *state);

#endif //STATE_H
