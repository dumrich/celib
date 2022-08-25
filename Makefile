include config.mk

SRC := $(wildcard src/*.c) $(wildcard src/*/*.c)
OBJ := $(SRC:c=o)

HEADERS := $(wildcard src/*.h) $(wildcard src/*/*.h)

all: ${BIN} install

${BIN}: ${OBJ}
	${CC} ${CFLAGS} -shared -o $@ ${OBJ}

%.o: %.c
	${CC} -c ${CFLAGS} -o $@ $<

install: ${BIN}
	cp ${BIN} ${INSTALL}/lib/${BIN}
	cp $

	mkdir ${INSTALL}/include/celib
	cp $(wildcard src/celib/*.h) ${INSTALL}/include/celib

	cp src/celib.h ${INSTALL}/include

linked: ${BIN}
	${CC} -lce tests/linked_list_test.c -o linked_list_test 

.PHONY: clean
clean:
	rm -rf ${BIN} ${OBJ} 
