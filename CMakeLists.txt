cmake_minimum_required(VERSION 3.7.1)
project( poker-eval VERSION 138.0 )

add_definitions(
    -D_UNICODE
    -DUNICODE
    )

add_compile_options(
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<C_COMPILER_ID:GNU>>:"-Wall -Wpointer-arith -Wstrict-prototypes">
    )

include( cmake/SystemCheck.cmake )
configure_file(
    include/config.h.in 
    ${CMAKE_SOURCE_DIR}/include/config.h 
    )

configure_file( 
    include/poker_config.h.in 
    ${CMAKE_SOURCE_DIR}/include/poker_config.h 
    )

configure_file(
    tests/run.in 
    ${CMAKE_SOURCE_DIR}/tests/run 
    )

add_subdirectory(
    lib
    )

add_subdirectory(
    examples
    )

#add_subdirectory(
#tests
#)
