# icepool-driver
A C library for interfacing with [`icepool-board`](https://github.com/jkiv/icepool-board) on Linux using [libftdi](https://www.intra2net.com/en/developer/libftdi/).

### Building

Building requires `make`, `gcc`, `libftdi1`, and `libusb`.

```
$ make -C src/ all
```

This will produce `libicepool.so` and `libicepool-d.so` shared libraries in `src/`.

### Python3 Bindings

This project also contains Python3 bindings for the `libicepool.so` shared library.

```
$ make -C src/ python
```

This will produce `icepool-1.0.0.tar.gz` in `src/bindings/python3-ctypes/dist`.

> TODO `pip install icepool`

### API

> TODO

### Donate

Please consider supporting this project and others like it by donating:

* ☕: [ko-fi.com/jkiv_](https://ko-fi.com/jkiv_)
* ₿: `13zRrs1YDdooUN5WtfXRSDn8KnJdok4qG9`
