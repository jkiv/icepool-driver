#include <stdlib.h>
#include <stdio.h>
#include "munit/munit.h"
#include "icepool.h"

#define BUFFER_DEPTH 32
#define NUMBER_OF_BOARDS 1

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
    uint8_t data_out[NUMBER_OF_BOARDS*BUFFER_DEPTH/8] = { 0 };
    uint8_t data_in[NUMBER_OF_BOARDS*BUFFER_DEPTH/8] = { 0 };

    const size_t data_len = NUMBER_OF_BOARDS*BUFFER_DEPTH/8;

    // Set up data
    for(size_t i = 0; i < data_len; i++)
    {
        data_out[i] = (uint8_t)(i & 0xFF);
    }

    // Create icepool context and send/receive data

    IcepoolContext* ctx = icepool_new();

    if (ctx == NULL || icepool_has_error(ctx)) {
        fprintf(stderr, "Could not initialize IcepoolContext. Quitting...\n");
        exit(EXIT_FAILURE);
    }

    icepool_spi_assert_daisy(ctx);

    munit_assert(!icepool_has_error(ctx));

    icepool_spi_write_daisy(ctx, data_out, data_len);

    munit_assert(!icepool_has_error(ctx));

    icepool_spi_read_daisy(ctx, data_in, data_len);

    munit_assert(!icepool_has_error(ctx));

    icepool_spi_deassert_daisy(ctx);

    munit_assert(!icepool_has_error(ctx));

    icepool_free(ctx);

    // Test data
    printf("data_out:\n");
    print_buffer(data_out, data_len);

    printf("data_in:\n");
    print_buffer(data_in, data_len);

    munit_assert_memory_equal(data_len, data_out, data_in);

    return EXIT_SUCCESS;
}