cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Add hello library subdirectory
add_subdirectory(hello)

# Add test libraries for error state testing
add_subdirectory(test_libs/noentry)
add_subdirectory(test_libs/nullret)
add_subdirectory(test_libs/badver)
add_subdirectory(test_libs/empty)

