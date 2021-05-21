CC                 = g++
CFLAGS             = -std=c++20
PATH_HEADER_CP     = kargo.cpp
PATH_HEADER_H      = main.cpp

all:
	${CC} ${PATH_HEADER_CP} ${PATH_HEADER_H} ${CFLAGS}
