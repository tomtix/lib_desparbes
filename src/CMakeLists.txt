add_library(stack STATIC stack.c)
add_library(swap STATIC swap.c)
add_library(list STATIC list.c)

install(TARGETS stack swap list DESTINATION lib)