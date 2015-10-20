add_executable(test_list test_list.c)
set_target_properties(test_list PROPERTIES COMPILE_FLAGS -DTEST)
target_link_libraries(test_list list)
add_test(test_list test_list)

add_executable(test_stack test_stack.c)
set_target_properties(test_stack PROPERTIES COMPILE_FLAGS -DTEST)
target_link_libraries(test_stack stack)
add_test(test_stack test_stack)

add_executable(test_swap test_swap.c)
set_target_properties(test_swap PROPERTIES COMPILE_FLAGS -DTEST)
target_link_libraries(test_swap swap)
add_test(test_swap test_swap)

add_executable(test_state test_state.c)
set_target_properties(test_state PROPERTIES COMPILE_FLAGS -DTEST)
target_link_libraries(test_state state)
add_test(test_state test_state)

add_executable(test_search test_search.c)
set_target_properties(test_search PROPERTIES COMPILE_FLAGS -DTEST)
target_link_libraries(test_search search)
add_test(test_search test_search)

add_executable(test_queue test_queue.c)
set_target_properties(test_queue PROPERTIES COMPILE_FLAGS -DTEST)
target_link_libraries(test_queue queue)
add_test(test_queue test_queue)