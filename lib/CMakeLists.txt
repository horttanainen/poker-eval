project(libpoker)

set(
    BASIC_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_nbits.c
    ${CMAKE_CURRENT_BINARY_DIR}/t_topbit.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_topcard.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_topfivecards.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_topfivebits.c
    ${CMAKE_CURRENT_BINARY_DIR}/t_toptwobits.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_cardmasks.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_maskrank.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_straight.c 
    )

set(
    JOKER_TABLES 
    ${CMAKE_CURRENT_BINARY_DIR}/t_jokercardmasks.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_jokerstraight.c
    )

set(
    PACKED_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_nbitsandstr.c
    )

set(
    EVX_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_evx_pairval.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_evx_strval.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_evx_tripsval.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_evx_flushcards.c
    )

set(
    ASTUD_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_astudcardmasks.c
    )

set(
    LOWBALL_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_botfivecards.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_botcard.c 
    ${CMAKE_CURRENT_BINARY_DIR}/t_botfivecardsj.c
    )

set(
    TABLES
    ${BASIC_TABLES} 
    ${JOKER_TABLES} 
    ${PACKED_TABLES} 
    ${EVX_TABLES} 
    ${ASTUD_TABLES}
    ${LOWBALL_TABLES}
    )

file( 
    GLOB POKER_EVAL_SOURCES
    combinations.c
    deck.c
    deck_astud.c
    deck_joker.c
    deck_std.c
    enumerate.c
    enumord.c
    evx.c
    lowball.c
    rules_astud.c
    rules_joker.c
    rules_std.c
    poker_wrapper.c
    )

set(
    LIBPOKER_SOURCE_FILES
    ${POKER_EVAL_SOURCES}
    ${TABLES}
    )

file( 
    GLOB_RECURSE LIBPOKER_INCLUDE_FILES
    ${CMAKE_SOURCE_DIR}/include/*.h
    )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    )

add_library(
    ${PROJECT_NAME} SHARED
    ${LIBPOKER_INCLUDE_FILES}
    ${LIBPOKER_SOURCE_FILES}
    )

set_target_properties(
    ${PROJECT_NAME} 
    PROPERTIES LINKER_LANGUAGE CXX
    )

file( GLOB
    MKTABLE_HELPERS
    mktable.c 
    mktable_utils.c
    )

add_executable(
    mktab_basic
    mktab_basic.c
    ${MKTABLE_HELPERS}
    )

add_custom_command(
    OUTPUT ${BASIC_TABLES}
    COMMAND mktab_basic
    DEPENDS mktab_basic
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    )

add_executable(
    mktab_joker
    mktab_joker.c
    ${MKTABLE_HELPERS}
    )

add_custom_command(
    OUTPUT ${JOKER_TABLES}
    COMMAND mktab_joker
    DEPENDS mktab_joker
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    )

add_executable(
    mktab_packed
    mktab_packed.c
    ${MKTABLE_HELPERS}
    )

add_custom_command(
    OUTPUT ${PACKED_TABLES}
    COMMAND mktab_packed
    DEPENDS mktab_packed
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    )

add_executable(
    mktab_evx
    mktab_evx.c
    ${MKTABLE_HELPERS}
    )

add_custom_command(
    OUTPUT ${EVX_TABLES}
    COMMAND mktab_evx
    DEPENDS mktab_evx
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    )

add_executable(
    mktab_astud
    mktab_astud.c
    ${MKTABLE_HELPERS}
    )

add_custom_command(
    OUTPUT ${ASTUD_TABLES}
    COMMAND mktab_astud
    DEPENDS mktab_astud
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    )

add_executable(
    mktab_lowball
    mktab_lowball.c
    ${MKTABLE_HELPERS}
    )

add_custom_command(
    OUTPUT ${LOWBALL_TABLES}
    COMMAND mktab_lowball
    DEPENDS mktab_lowball
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    )

add_executable(
    evx_gen5
    evx_generate.c
    )

target_compile_options(
    evx_gen5
    PUBLIC "-DCARDS_DEALT=5"
    )

add_executable(
    evx_gen7
    evx_generate.c
    )

target_compile_options(
    evx_gen7
    PUBLIC "-DCARDS_DEALT=7"
    )

set(
    EVX5_INLINE
    ${CMAKE_SOURCE_DIR}/include/inlines/evx5.h
    )

set(
    EVX7_INLINE
    ${CMAKE_SOURCE_DIR}/include/inlines/evx7.h
    )

set(
    EVX_PREAMPLE_CFRAG
    ${CMAKE_CURRENT_SOURCE_DIR}/evx_preamble.cfrag
    )

add_custom_command(
    OUTPUT ${EVX5_INLINE}
    COMMAND evx_gen5 ${CMAKE_CURRENT_SOURCE_DIR} > ${EVX5_INLINE}
    DEPENDS evx_gen5 ${EVX_PREAMPLE_CFRAG}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    )

add_custom_command(
    OUTPUT ${EVX7_INLINE}
    COMMAND evx_gen7 ${CMAKE_CURRENT_SOURCE_DIR} > ${EVX7_INLINE}
    DEPENDS evx_gen7 ${EVX_PREAMPLE_CFRAG}
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    )
