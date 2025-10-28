set(REXLIB_SRC_FILES
	rexhost/keytext.c
	rexhost/rexload.c

	aasyslib.c
	stdiolib.c
	)

add_library(minirex ${REXLIB_SRC_FILES})
target_include_directories(minirex PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/inc")

