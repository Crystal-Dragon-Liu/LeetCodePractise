file(GLOB LEETCODEPRACTICE_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*/*test.cpp")
find_program(VALGRIND_BIN valgrind)
if ("${VALGRIND_BIN}" STREQUAL "VALGRIND_BIN-NOTFOUND")
    message(WARNING "LeetCodePractise/test couldn't find valgrind.")
else()
    message(STATUS "LeetCodePractise/test found valgrind at ${VALGRIND_BIN}")
endif()

set(VALGRIND_OPTIONS
        --error-exitcode=1                      # if leaks are detected, return nonzero value
        # --gen-suppressions=all  # uncomment for leak suppression syntax
        --leak-check=full                       # detailed leak information
        --soname-synonyms=somalloc=*jemalloc*   # also intercept jemalloc
        --trace-children=yes                    # trace child processes
        --track-origins=yes                     # track origin of uninitialized values
        )
set(VALGRIND_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/build_support/valgrind.supp")

##########################################
# "make LYB_test"
##########################################

foreach(leetcodepractice_test_source ${LEETCODEPRACTICE_TEST_SOURCES})
    #create a human readable name
    get_filename_component(leetcodepractice_test_filename ${leetcodepractice_test_source} NAME)
    string(REPLACE ".cpp" "" leetcodepractice_test_name ${leetcodepractice_test_filename})
    # Add the test target separately and as part of "make check-tests".
    add_executable(${leetcodepractice_test_name} EXCLUDE_FROM_ALL ${leetcodepractice_test_source})

    target_link_libraries(${leetcodepractice_test_name} LeetCodePractice_shared gtest gmock_main)

    # Set test target properties and dependencies.
    set_target_properties(${leetcodepractice_test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
        COMMAND ${leetcodepractice_test_name}
    )
    # Add the test under CTest.
    add_test(${leetcodepractice_test_name} ${VALGRIND_BIN} ${VALGRIND_OPTIONS}
    --suppressions=${VALGRIND_SUPPRESSIONS_FILE} ${CMAKE_BINARY_DIR}/test/${leetcodepractice_test_name}
    --gtest_color=yes --gtest_output=xml:${CMAKE_BINARY_DIR}/test/unit_${test_name}.xml)
    add_test(${leetcodepractice_test_name} ${CMAKE_BINARY_DIR}/test/${leetcodepractice_test_name} --gtest_color=yes
            --gtest_output=xml:${CMAKE_BINARY_DIR}/test/${leetcodepractice_test_name}.xml)


endforeach(leetcodepractice_test_source)
