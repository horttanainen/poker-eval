project(poker-eval)

set(
    BASIC_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_nbits.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/t_topbit.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_topcard.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_topfivecards.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_topfivebits.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/t_toptwobits.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_cardmasks.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_maskrank.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_straight.cpp 
    )

set(
    JOKER_TABLES 
    ${CMAKE_CURRENT_BINARY_DIR}/t_jokercardmasks.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_jokerstraight.cpp
    )

set(
    PACKED_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_nbitsandstr.cpp
    )

set(
    EVX_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_evx_pairval.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_evx_strval.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_evx_tripsval.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_evx_flushcards.cpp
    )

set(
    ASTUD_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_astudcardmasks.cpp
    )

set(
    LOWBALL_TABLES
    ${CMAKE_CURRENT_BINARY_DIR}/t_botfivecards.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_botcard.cpp 
    ${CMAKE_CURRENT_BINARY_DIR}/t_botfivecardsj.cpp
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
    combinations.cpp
    deck.cpp
    deck_astud.cpp
    deck_joker.cpp
    deck_std.cpp
    enumerate.cpp
    enumord.cpp
    evx.cpp
    lowball.cpp
    rules_astud.cpp
    rules_joker.cpp
    rules_std.cpp
    poker_wrapper.cpp
    )

set(
    POKER_EVAL_SOURCES_WITH_LOOKUPS
    ${POKER_EVAL_SOURCES}
    ${TABLES}
    )

file( 
    GLOB_RECURSE POKER_EVAL_INCLUDE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    )

list(
    REMOVE_ITEM 
    POKER_EVAL_INCLUDE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/mktable.h
    )

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    )

add_library(
    ${PROJECT_NAME} SHARED
    ${POKER_EVAL_INCLUDE_FILES}
    ${POKER_EVAL_SOURCES_WITH_LOOKUPS}
    )

include (GenerateExportHeader)
generate_export_header(
    ${PROJECT_NAME}
    BASE_NAME pokereval
    )

#set_target_properties(
#${PROJECT_NAME} 
#PROPERTIES LINKER_LANGUAGE CXX
#)

set(
    ${PROJECT_NAME}_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE
    )

file( GLOB
    MKTABLE_HELPERS
    mktable.cpp 
    mktable_utils.cpp
    )

add_executable(
    mktab_basic
    mktab_basic.cpp
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
    mktab_joker.cpp
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
    mktab_packed.cpp
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
    mktab_evx.cpp
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
    mktab_astud.cpp
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
    mktab_lowball.cpp
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
    evx_generate.cpp
    )

target_compile_options(
    evx_gen5
    PUBLIC "-DCARDS_DEALT=5"
    )

add_executable(
    evx_gen7
    evx_generate.cpp
    )

target_compile_options(
    evx_gen7
    PUBLIC "-DCARDS_DEALT=7"
    )

set(
    EVX5_INLINE
    ${CMAKE_CURRENT_SOURCE_DIR}/inlines/evx5.h
    )

set(
    EVX7_INLINE
    ${CMAKE_CURRENT_SOURCE_DIR}/inlines/evx7.h
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
