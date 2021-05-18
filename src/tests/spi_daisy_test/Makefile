VENDOR_PATH=../vendor/
MUNIT_C_PATH=../vendor/munit/munit.c
ICEPOOL_PATH=../../
LIBICEPOOL_PATH=../../
FTDI_PATH=/usr/include/ftdi1
LIBFTDI_PATH=/usr/lib

.phony : run
run : flash spi_daisy_test
	./spi_daisy_test

.phony : spi_daisy_test
spi_daisy_test : spi_daisy_test.c libicepool-d.a $(MUNIT_C_PATH)
	gcc --std=c99 -g -o $@ -I$(VENDOR_PATH) -I$(ICEPOOL_PATH) -I$(FTDI_PATH) $< $(MUNIT_C_PATH) -L$(LIBICEPOOL_PATH) -licepool-d -L$(LIBFTDI_PATH) -lftdi1

.phony : clean
clean :
	make -C rtl/ clean
	rm -f spi_daisy_test

.phony : libicepool-d.a
libicepool-d.a :
	make -C $(ICEPOOL_PATH) $@

.phony : flash 
flash :
	make -C rtl/ flash