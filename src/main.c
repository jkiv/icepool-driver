#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "icepool.h"

int test_spi_shared_ready()
{   
    IcepoolContext* ctx = icepool_new();

    icepool_spi_assert_shared(ctx);

    printf("READY? %s\n", icepool_read_ready_flag(ctx) ? "true" : "false");

    for(size_t n = 0; n < 1024/8; n++)
    {
        uint8_t ones = 0xFF;
        icepool_spi_write_shared(ctx, &ones, 1);
    }

    icepool_spi_deassert_shared(ctx);

    printf("READY? %s\n", icepool_read_ready_flag(ctx) ? "true" : "false");

    icepool_free(ctx);

    return EXIT_SUCCESS;
}

int test_spi_daisy()
{
    IcepoolContext* ctx = icepool_new();

    uint8_t data_out[256] = { 0 };
    uint8_t data_in[256] = { 0 };

    for(size_t n = 0; n < 256; n++)
    {
        data_out[n] = n & 0xFF;
    }

    icepool_spi_assert_daisy(ctx);

    icepool_spi_exchange_daisy(ctx, data_out, data_in, 256);

    icepool_spi_deassert_daisy(ctx);
    
    for(size_t n = 0; n < 256; n++)
    {
        printf("%02X\n", data_in[n]);
    }

    return EXIT_SUCCESS;
}

int main(int argn, const char* args[])
{
    // TODO proper tests
    return test_spi_shared_ready();
    // return test_spi_daisy();
}