.phony: all
all : libicepool libicepool-d

.phony: libicepool-d
libicepool-d: libicepool-d.a libicepool-d.so

.phony: libicepool
libicepool: libicepool.a libicepool.so

.phony: clean
clean: clean_python
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


###

ICEPOOL_PY_DIR=bindings/python-ctypes/
ICEPOOL_PY_SRC_DIR=$(ICEPOOL_PY_DIR)src/icepool/

.phony : python
python : $(ICEPOOL_PY_SRC_DIR)libicepool.so $(ICEPOOL_PY_SRC_DIR)icepool.py
	python3 -m build $(ICEPOOL_PY_DIR) 

$(ICEPOOL_PY_SRC_DIR)libicepool.so : libicepool.so
	cp -a libicepool.so $(ICEPOOL_PY_SRC_DIR)

.phony : clean_python
clean_python :
	rm -f $(ICEPOOL_PY_SRC_DIR)libicepool.so
	rm -rf $(ICEPOOL_PY_DIR)build $(ICEPOOL_PY_DIR)dist
	rm -rf $(ICEPOOL_PY_DIR)src/*.egg-info/