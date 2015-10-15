add_library(stack STATIC stack.c)
add_library(swap STATIC swap.c)
add_library(list STATIC list.c)
add_library(state STATIC state.c)
add_library(search STATIC search.c)

install(TARGETS stack swap list state search DESTINATION lib)