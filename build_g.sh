#!/bin/sh
export LD_PRELOAD=
CFLAG=""
CFLAG+=" -DNDEBUG"
CFLAG+=" -O3"
CFLAG+=" -mlzcnt"
CFLAG+=" -mbmi"
CFLAG+=" -lpthread"
CFLAG+=" -latomic"
CFLAG+=" -shared"
CFLAG+=" -fpic"
CFLAG+=" -fno-builtin-malloc"
CFLAG+=" -fno-builtin-free"
CFLAG+=" -fno-builtin-calloc"
CFLAG+=" -fno-builtin-realloc"
CFLAG+=" -fno-builtin-posix_memalign"
CFLAG+=" -fno-builtin-aligned_alloc"
CFLAG+=" -fno-builtin-valloc"
CFLAG+=" -fno-builtin-memalign"
CFLAG+=" -fno-builtin-pvalloc"
CFLAG+=" -fno-builtin-malloc_usable_size"

g++ -DKANAMESHIKI_HEAP_SPECIALIZATION=1 src/KanameShiki.cpp ${CFLAG} -o libKanameShiki1_g.so
g++ -DKANAMESHIKI_HEAP_SPECIALIZATION=0 src/KanameShiki.cpp ${CFLAG} -o libKanameShiki0_g.so

g++ -c -DKANAMESHIKI_HEAP_SPECIALIZATION=1 src/KanameShiki.cpp ${CFLAG} -o KanameShiki1_g.o
g++ -c -DKANAMESHIKI_HEAP_SPECIALIZATION=0 src/KanameShiki.cpp ${CFLAG} -o KanameShiki0_g.o

ar rcs libKanameShiki1_g.a KanameShiki1_g.o
ar rcs libKanameShiki0_g.a KanameShiki0_g.o
