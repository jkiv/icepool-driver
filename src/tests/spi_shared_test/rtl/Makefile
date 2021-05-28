TEST_NAME=spi_shared_test

NEXTPNR=nextpnr-ice40
NEXTPNR_DEVICE=--hx8k
NEXTPNR_PACKAGE=bg121

PCF_FILE=pinout-icepool-ice40hx8k.pcf

$(TEST_NAME).bin: $(TEST_NAME).asc
	icepack $^ $@ 
	
$(TEST_NAME).asc: $(TEST_NAME).json $(PCF_FILE) 
	$(NEXTPNR) --package $(NEXTPNR_PACKAGE) $(NEXTPNR_DEVICE) --json $(TEST_NAME).json --pcf $(PCF_FILE) --asc $(TEST_NAME).asc

$(TEST_NAME).json : top.v
	yosys -p 'synth_ice40 -top top -json $@ -abc2 -retime' $^

.phony : build
build : $(TEST_NAME).bin

.phony : flash
flash : $(TEST_NAME).bin
	#iceprog -v -s -S $^
	iceprog -v -S $^

.phony: clean
clean:
	rm -f *.json *.asc *.bin
