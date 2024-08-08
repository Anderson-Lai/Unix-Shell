

project(shell_exec C)

add_executable(${PROJECT_NAME}
    #"${CMAKE_SOURCE_DIR}/tests/vector_tests.c"
    #"${CMAKE_SOURCE_DIR}/tests/string_tests.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.c"

    "${CMAKE_CURRENT_SOURCE_DIR}/shell.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/parse.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/vector.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/str.c"
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")

if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME} PUBLIC 
        $<$<CONFIG:Debug>:-g -fsanitize=address>
        $<$<CONFIG:Release>:"">
    )
    target_link_options(${PROJECT_NAME} PUBLIC 
        $<$<CONFIG:Debug>:-g -fsanitize=address>
        $<$<CONFIG:Release>:"">
    )
else()
    message(FATAL_ERROR "Your compiler is not supported")
endif()
