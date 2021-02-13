icepool_test : main.c icepool.c icepool.h
	gcc -std=c99 -Wall -g -I/usr/include/ftdi1 -L/usr/lib -L/usr/local/lib -o icepool_test main.c icepool.c -lftdi1 -lusb-1.0 -ludev -lpthread

.phony: clean
clean:
	rm -f icepool_test