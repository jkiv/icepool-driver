.phony: all
all : libicepool libicepool-d

.phony: libicepool-d
libicepool-d: libicepool-d.a

.phony: libicepool
libicepool: libicepool.a

.phony: clean
clean:
	rm -f icepool.o libicepool.a  icepool-d.o libicepool-d.a

libicepool.a : icepool.o
	ar rcs libicepool.a icepool.o

icepool.o : icepool.c icepool.h
	gcc -std=c99 -Wall -fPIC -c -I/usr/include/ftdi1 -L/usr/lib -L/usr/local/lib -o icepool.o icepool.c -lftdi1 -lusb-1.0 -ludev -lpthread

libicepool-d.a : icepool-d.o
	ar rcs libicepool-d.a icepool-d.o

icepool-d.o : icepool.c icepool.h
	gcc -std=c99 -Wall -g -fPIC -c -I/usr/include/ftdi1 -o icepool-d.o icepool.c -L/usr/lib -lftdi1 -lpthread -L/usr/local/lib -lusb-1.0 -ludev