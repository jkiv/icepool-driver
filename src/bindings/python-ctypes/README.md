# icepool-py

## About

`icepool-py` is a Python wrapper for the [`icepool-driver`](https://github.com/jkiv/icepool-driver) C library.

## Dependencies

`TODO`

## Build & Install

`TODO`

## Example

```python
from icepool import icepool

message = b'Hello, World!'

ctx = icepool.IcepoolContext()

ctx.spi_assert_daisy()

ctx.spi_write_daisy(message)

print(ctx.spi_read_daisy())

ctx.spi_deassert_daisy()
```



## API

`TODO`