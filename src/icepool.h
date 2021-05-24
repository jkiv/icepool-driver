#ifndef __ICEPOOL_H__
#define __ICEPOOL_H__

#include <stdint.h>
#include <stdbool.h>

#include <ftdi.h>

#define ICEPOOL_DEVICE_COUNT_MAX 16

typedef enum
{
    ICEPOOL_OK = 0,
    ICEPOOL_NO_DEVICE_FOUND,
    //
    ICEPOOL_LIBUSB_ERROR,
    ICEPOOL_LIBFTDI_ERROR,
    ICEPOOL_UNKNOWN_ERROR
} IcepoolError;

typedef enum
{
    ICEPOOL_FTDI_FT232H,
    ICEPOOL_FTDI_FT2232H,
    ICEPOOL_FTDI_FT4232H,
    ICEPOOL_UNKNOWN_DEVICE_TYPE
} IcepoolFtdiDeviceType;

typedef struct
{
    uint8_t data;
    uint8_t dir;
} Icepool_MpsseGpioState;

typedef struct
{
    // FTDI context (libftdi)
    struct ftdi_context* ftdi;

    // Last error
    IcepoolError error;

    // Kind of device context connected to
    IcepoolFtdiDeviceType device_type;

    // Maintain record of GPIO states
    // TODO Port B
    Icepool_MpsseGpioState gpio_state_lower;
    Icepool_MpsseGpioState gpio_state_upper;

} IcepoolContext;

IcepoolContext* icepool_new();
void icepool_init(IcepoolContext* ctx);
void icepool_deinit(IcepoolContext* ctx);
void icepool_free(IcepoolContext* ctx);

// Shared SPI interface
// ... no read, exchange
void icepool_spi_assert_shared(IcepoolContext* ctx);
void icepool_spi_deassert_shared(IcepoolContext* ctx);
void icepool_spi_write_shared(IcepoolContext* ctx, uint8_t data[], size_t data_length);

// Daisy-chained SPI interface
void icepool_spi_assert_daisy(IcepoolContext* ctx);
void icepool_spi_deassert_daisy(IcepoolContext* ctx);
void icepool_spi_read_daisy(IcepoolContext* ctx, uint8_t data[], size_t data_length);
void icepool_spi_write_daisy(IcepoolContext* ctx, uint8_t data[], size_t data_length);
void icepool_spi_exchange_daisy(IcepoolContext* ctx, uint8_t data_out[], uint8_t data_in[], size_t data_length);

// READY flag
bool icepool_poll_ready(IcepoolContext* ctx);

// RESET
void icepool_assert_reset(IcepoolContext* ctx);
void icepool_deassert_reset(IcepoolContext* ctx);

#endif /* __ICEPOOL_H__ */