CC=aarch64-linux-musl-gcc
CCSTRIP=aarch64-linux-musl-strip
CCFLAGS=--static

all: init.o
	${CC} ${CCFLAGS} init.c -o init
	${CCSTRIP} init

clean:
	rm -f init *.o
