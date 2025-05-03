add_executable(concepts_test concepts_test.cpp)
target_link_libraries(concepts_test
        PRIVATE dp_concepts
)

add_test(NAME concepts_test COMMAND concepts_test)