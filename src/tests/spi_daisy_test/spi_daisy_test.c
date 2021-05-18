#include <stdlib.h>
#include <stdio.h>
#include "munit/munit.h"
#include "icepool.h"

#define BUFFER_DEPTH 32
#define NUMBER_OF_BOARDS 3

void print_buffer(const uint8_t* buffer, size_t buffer_len)
{
    for(size_t i = 0; i < buffer_len; )
    {
        for (size_t j = 0; j < 8 && i < buffer_len; j++, i++)
        {
            printf("%02x ", buffer[i]);
        }
        printf("\n");
    }
}

int main()
{
    uint8_t data_out[BUFFER_DEPTH] = { 0 };
    uint8_t data_in[BUFFER_DEPTH] = { 0 };

    const size_t data_len = BUFFER_DEPTH;

    // Set up data
    for(size_t i = 0; i < data_len; i++)
    {
        data_out[i] = (uint8_t)(i & 0xFF);
    }

    // Create icepool context and send/receive data

    IcepoolContext* ctx = icepool_new();

    icepool_spi_assert_daisy(ctx);
    icepool_spi_exchange_daisy(ctx, data_out, data_in, data_len);
    icepool_spi_exchange_daisy(ctx, data_out, data_in, data_len);
    icepool_spi_exchange_daisy(ctx, data_out, data_in, data_len);
    icepool_spi_exchange_daisy(ctx, data_out, data_in, data_len);
    icepool_spi_deassert_daisy(ctx);

    icepool_free(ctx);

    // Test data
    printf("data_in:\n");
    print_buffer(data_out, data_len);

    printf("data_in:\n");
    print_buffer(data_in, data_len);

    munit_assert_memory_equal(data_len, data_out, data_in);

    /*
    for (size_t i = 0; i < data_len / 2; i++)
    {
        if (data_out[i] != data_in[32+i])
            return EXIT_FAILURE;
    }
    */

    return EXIT_SUCCESS;
}