set(Test creatorTesting)

add_executable(${Test} main.cpp)

target_link_libraries(${Test} PUBLIC
        gtest_main
        gmock_main
    )

add_test(
        NAME ${Test}
        COMMAND ${Test}
    )

