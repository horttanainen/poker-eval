cmake_minimum_required(VERSION 3.7.1)
project( poker-eval VERSION 138.0 )

add_definitions(
    -D_UNICODE
    -DUNICODE
    -DHAVE_CONFIG_H
    )

add_compile_options(
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<C_COMPILER_ID:GNU>>:"-Wall -Wpointer-arith -Wstrict-prototypes">
    )

add_compile_options(
    $<$<CXX_COMPILER_ID:MSVC>:/wd4996>
    )
	
include( cmake/SystemCheck.cmake )
configure_file(
    poker-eval/config.h.in 
    ${CMAKE_CURRENT_SOURCE_DIR}/poker-eval/config.h 
    )

configure_file( 
    poker-eval/poker_config.h.in 
    ${CMAKE_CURRENT_SOURCE_DIR}/poker-eval/poker_config.h 
    )

configure_file(
    tests/run.in 
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/run 
    )

add_subdirectory(
    poker-eval
    )

#add_subdirectory(
#examples
#)

#add_subdirectory(
#tests
#)
