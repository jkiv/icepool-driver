VENDOR_PATH=../vendor/
MUNIT_C_PATH=../vendor/munit/munit.c
ICEPOOL_PATH=../../
LIBICEPOOL_PATH=../../
FTDI_PATH=/usr/include/ftdi1
LIBFTDI_PATH=/usr/lib

TEST_NAME=spi_daisy_test

.phony : build
build : $(TEST_NAME) gateware

.phony : run
run : $(TEST_NAME) flash
	./$(TEST_NAME)

$(TEST_NAME): main.c libicepool-d.a $(MUNIT_C_PATH)
	#gcc --std=c99 -g -o $@ -I$(VENDOR_PATH) -I$(ICEPOOL_PATH) -I$(FTDI_PATH) $< $(MUNIT_C_PATH) -L$(LIBICEPOOL_PATH) -licepool-d -L$(LIBFTDI_PATH) -lftdi1
	gcc --std=c99 -g -o $@ -I$(VENDOR_PATH) -I$(ICEPOOL_PATH) -I$(FTDI_PATH) $< $(LIBICEPOOL_PATH)libicepool-d.a $(MUNIT_C_PATH) -L$(LIBFTDI_PATH) -lftdi1

.phony : clean
clean :
	make -C rtl/ clean
	rm -f $(TEST_NAME)

.phony : libicepool-d.a
libicepool-d.a :
	make -C $(ICEPOOL_PATH) $@

.phony : gateware
gateware :
	make -C rtl/ build

.phony : flash 
flash :
	make -C rtl/ flash