#ifndef __ICEPOOL_H__
#define __ICEPOOL_H__

#include <stdint.h>
#include <stdbool.h>

#include <ftdi.h>

#define ICEPOOL_DEVICE_COUNT_MAX 16

typedef enum IcepoolFtdiInterface_t
{
    ICEPOOL_FTDI_FT232H,
    ICEPOOL_FTDI_FT2232H,
    UNKNOWN_VERSION
} IcepoolFtdiInterface;

typedef enum IcepoolSpiInterface_t
{
    ICEPOOL_SPI_INTERFACE_SHARED,
    ICEPOOL_SPI_INTERFACE_DAISY,
    UNKNOWN_INTERFACE
} IcepoolSpiInterface;

typedef struct Icepool_MpsseGpioState_t
{
    uint8_t data;
    uint8_t dir;
} Icepool_MpsseGpioState;

typedef struct IcepoolContext_t
{
    struct ftdi_context* ftdi;
    IcepoolFtdiInterface ftdi_interface;

    // FUTURE?
    uint8_t device_count;
    //IcepoolDevice devices[ICEPOOL_DEVICE_COUNT_MAX];
    
    // Maintain record of GPIO states
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

// GPIO helpers
void icepool_gpio_set_bit_lower(IcepoolContext* ctx, uint8_t pin, bool value);
void icepool_gpio_set_bit_upper(IcepoolContext* ctx, uint8_t pin, bool value);
uint8_t icepool_gpio_get_bit_lower(IcepoolContext* ctx, uint8_t pin);
uint8_t icepool_gpio_get_bit_upper(IcepoolContext* ctx, uint8_t pin);

#define ICEPOOL_SPI_SCK0_PIN 0
#define ICEPOOL_SPI_SDO0_PIN 1
#define ICEPOOL_SPI_CS0_PIN 4

#define ICEPOOL_SPI_CDONE_PIN 6
#define ICEPOOL_SPI_CRESET_B_PIN 7

#define ICEPOOL_SPI_SCK1_PIN 0
#define ICEPOOL_SPI_SDO1_PIN 1
#define ICEPOOL_SPI_SDI1_PIN 2
#define ICEPOOL_SPI_CS1_PIN 4

#define ICEPOOL_SPI_READY_PIN 6
#define ICEPOOL_SPI_RW_PIN 7

#endif /* __ICEPOOL_H__ */