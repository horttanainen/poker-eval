set( PACKAGE_NAME ${PROJECT_NAME} )
set( PACKAGE_VERSION ${PROJECT_VERSION} )
set( VERSION ${PROJECT_VERSION} )
set( PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}" )

find_program(AWK "awk")
find_program(MD5SUM "md5sum")
if(NOT MD5SUM)
    find_program(MD5SUM "md5")
endif()
find_program(VALGRIND "valgrind")

if(WIN32)
    set( EXEEXT .exe )
    set( OBJEXT .obj )
else()
    set( OBJEXT .o )
endif()

include(CheckFunctionExists)
check_function_exists(strerror HAVE_STRERROR)
if(NOT HAVE_STRERROR)
    set( LIBS "-lcposix ${LIBS}" )
    set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LIBS}" )
    set( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${LIBS}" )
    set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${LIBS}" )
    set( CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} ${LIBS}" )
endif()

FOREACH(KEYWORD "inline" "__inline__" "__inline")
    IF(NOT DEFINED C_INLINE)
        TRY_COMPILE(C_HAS_${KEYWORD} "${CMAKE_BINARY_DIR}"
            "${CMAKE_SOURCE_DIR}/cmake/test_inline.c"
            COMPILE_DEFINITIONS "-Dinline=${KEYWORD}")
        IF(C_HAS_${KEYWORD})
            SET(C_INLINE TRUE)
            ADD_DEFINITIONS("-Dinline=${KEYWORD}")
        ENDIF(C_HAS_${KEYWORD})
    ENDIF(NOT DEFINED C_INLINE)
ENDFOREACH(KEYWORD)
IF(NOT DEFINED C_INLINE)
    ADD_DEFINITIONS("-Dinline=")
ENDIF(NOT DEFINED C_INLINE)

include(TestBigEndian)
test_big_endian(WORDS_BIGENDIAN)
check_type_size( long SIZEOF_LONG)
include(CheckIncludeFiles)
check_include_files(inttypes.h HAVE_INTTYPES_H)
check_include_files(unistd.h HAVE_UNISTD_H)
check_include_files(sys/stat.h HAVE_SYS_STAT_H)
include(CheckTypeSize)
check_type_size( "long long" LONG_LONG LANGUAGE C )
check_type_size( uint64_t UINT64_T LANGUAGE C)
check_type_size( int8 INT8 LANGUAGE C)