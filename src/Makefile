.phony: all
all : libicepool libicepool-d

.phony: libicepool-d
libicepool-d: libicepool-d.a libicepool-d.so

.phony: libicepool
libicepool: libicepool.a libicepool.so

.phony: clean
clean:
	rm -f icepool.o libicepool.a  icepool-d.o libicepool-d.a libicepool.so libicepool-d.so

###

libicepool.so : icepool.o
	gcc -shared -o $@ $^ -L/usr/lib -lftdi1

libicepool.a : icepool.o
	ar rcs libicepool.a icepool.o

icepool.o : icepool.c icepool.h
	gcc -std=c99 -Wall -fPIC -c -I/usr/include/ftdi1 -o icepool.o icepool.c
	#-L/usr/lib -L/usr/local/lib -lftdi1 -lusb-1.0 -ludev -lpthread

###

libicepool-d.so : icepool-d.o
	gcc -shared -o $@ $^ -L/usr/lib -lftdi1

libicepool-d.a : icepool-d.o
	ar rcs libicepool-d.a icepool-d.o

icepool-d.o : icepool.c icepool.h
	gcc -std=c99 -Wall -g -fPIC -c -I/usr/include/ftdi1 -o icepool-d.o icepool.c
	#-L/usr/lib -lftdi1 -lpthread -L/usr/local/lib -lusb-1.0 -ludev