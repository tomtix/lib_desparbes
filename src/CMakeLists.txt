add_library(stack STATIC stack.c)
add_library(swap STATIC swap.c)
add_library(list STATIC list.c)
add_library(state STATIC state.c)

install(TARGETS stack swap list state DESTINATION lib)