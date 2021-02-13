#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "icepool.h"

int main(int argn, const char* args[])
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

    //printf("%02X\n", data_in);
    //fflush(stdout);
    //sleep(1);
    
    for(size_t n = 0; n < 256; n++)
    {
        printf("%02X\n", data_in[n]);
    }

    
    return EXIT_SUCCESS;
}