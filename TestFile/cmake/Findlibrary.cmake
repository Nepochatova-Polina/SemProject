set(FIND_LIBRARY_PATHS
        ~/CLionProjects/Libraries/library)
find_path(LIBRARY_INCLUDE_DIR library.h
        PATH_SUFFIXES include
        PATHS ${FIND_LIBRARY_PATHS})
find_library(LIBRARY_LIBRARY
        NAMES library
        PATH_SUFFIXES lib
        PATHS ${FIND_LIBRARY_PATHS})

