cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# Build hello as a shared library
add_library(hello SHARED hello.c)

# Set output name to hello.poe for cross-platform compatibility
set_target_properties(hello PROPERTIES
    OUTPUT_NAME "hello"
    PREFIX ""
    SUFFIX ".poe"
)

# Set position independent code (required for shared libraries)
set_target_properties(hello PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# Include directories - need headers from src/inc and poco/include
target_include_directories(hello PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

# Link against libpoco (for Pocorex structure definitions)
target_link_libraries(hello PRIVATE libpoco)

# For Windows, symbols are exported via __declspec(dllexport) in source
if(WIN32)
    set_target_properties(hello PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS FALSE
    )
else()
    # Set visibility defaults for Linux/macOS
    target_compile_options(hello PRIVATE -fvisibility=default)
endif()

INSTALL(TARGETS hello DESTINATION ${CMAKE_INSTALL_PREFIX}/tests/)

# Install the demonstration script alongside tests
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/hello.poc DESTINATION ${CMAKE_INSTALL_PREFIX}/tests/)
