# FUTURE specify number of boards at runtime

import pytest

from icepool import icepool

def test_exchange_daisy():
    context = icepool.IcepoolContext()

    test_buffer = bytes((0x00, 0x01, 0x02, 0x03,))

    context.spi_assert_daisy()

    context.spi_exchange_daisy(test_buffer)

    result = context.spi_exchange_daisy(test_buffer)

    context.spi_deassert_daisy()

    assert(test_buffer == result)

def test_write_read_daisy():
    context = icepool.IcepoolContext()

    test_buffer = bytes((0x00, 0x01, 0x02, 0x03,))

    context.spi_assert_daisy()

    context.spi_write_daisy(test_buffer)

    result = context.spi_read_daisy(len(test_buffer))

    context.spi_deassert_daisy()

    assert(test_buffer == result)

if __name__ == '__main__':
    test_exchange_daisy()
    test_write_read_daisy()