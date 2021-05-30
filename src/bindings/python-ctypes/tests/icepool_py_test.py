# FUTURE specify number of boards at runtime

import pytest

from icepool import IcepoolContext

def test_exchange_daisy():
    context = IcepoolContext()

    test_buffer = b'\00\01\02\03'

    context.spi_assert_daisy()

    result = context.spi_exchange_daisy(test_buffer)

    context.spi_deassert_daisy()

    assert(test_buffer == result)

def test_write_read_daisy():
    context = IcepoolContext()

    test_buffer = b'\00\01\02\03'

    context.spi_assert_daisy()

    context.spi_write_daisy(test_buffer)

    result = context.spi_read_daisy(len(test_buffer))

    context.spi_deassert_daisy()

    assert(test_buffer == result)

if __name__ == '__main__':
    test_exchange_daisy()
    test_write_read_daisy()