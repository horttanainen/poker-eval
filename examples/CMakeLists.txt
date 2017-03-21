project(examples)

include_directories(
    ${libpoker_INCLUDE_DIRS}
    )

add_executable(
    eval
    eval.c
    )

target_link_libraries(
    eval
    libpoker
    )

add_executable(
    fish
    fish.c
    )

target_link_libraries(
    fish
    libpoker
    )

add_executable(
    five_card_hands
    five_card_hands.c
    getopt_w32.c
    )

target_link_libraries(
    five_card_hands
    libpoker
    )

add_executable(
    hcmp2
    hcmp2.c
    )

target_link_libraries(
    hcmp2
    libpoker
    )

add_executable(
    hcmpn
    hcmpn.c
    )

target_link_libraries(
    hcmpn
    libpoker
    )

add_executable(
    pokenum
    pokenum.c
    )

target_link_libraries(
    pokenum
    libpoker
    )

add_executable(
    seven_card_hands
    seven_card_hands.c
    )

target_link_libraries(
    seven_card_hands
    libpoker
    )

add_executable(
    usedecks
    usedecks.c
    )

target_link_libraries(
    usedecks
    libpoker
    )

