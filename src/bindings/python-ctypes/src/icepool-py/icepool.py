import ctypes
from os import path

# https://docs.python.org/3/library/ctypes.html

_libicepool_so_name = "libicepool.so"

_libicepool_so_path = path.abspath(path.join(path.dirname(__file__), _libicepool_so_name))

_libicepool = ctypes.CDLL(_libicepool_so_path, mode = ctypes.RTLD_GLOBAL)

def _function(function_name, return_type, arg_types):
    fn = _libicepool.__getattr__(function_name)
    fn.restype = return_type
    fn.argtypes = arg_types
    return fn

class IcepoolContext:
    def __init__(self):
        _icepool_new = _function('icepool_new', ctypes.c_void_p, None)
        self._ctx = _icepool_new()

    def __del__(self):
        _icepool_free = _function('icepool_free', None, [ctypes.c_void_p,])
        _icepool_free(self._ctx)
        self._ctx = None

    def __repr__(self):
        return f"IcepoolContext<@{self._ctx}>"

    def init():
        # FUTURE add just _alloc() for IcepoolContext
        pass

    def deinit():
        # FUTURE add just _free() for IcepoolContext
        pass

    def spi_assert_shared(self):
        _icepool_spi_assert_shared = _function('icepool_spi_assert_shared', None, [ctypes.c_void_p,])
        _icepool_spi_assert_shared(self._ctx)
    
    def spi_deassert_shared(self):
        _icepool_spi_deassert_shared = _function('icepool_spi_deassert_shared', None, [ctypes.c_void_p,])
        _icepool_spi_deassert_shared(self._ctx)
    
    def spi_write_shared(self, data_out):
        _icepool_spi_write_shared = _function('icepool_spi_write_shared', None, [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t,])
        _icepool_spi_write_shared(self._ctx, data_out, len(data_out))
    
    def spi_assert_daisy(self):
        _icepool_spi_assert_daisy = _function('icepool_spi_assert_daisy', None, [ctypes.c_void_p,])
        _icepool_spi_assert_daisy(self._ctx)
    
    def spi_deassert_daisy(self):
        _icepool_spi_deassert_daisy = _function('icepool_spi_deassert_daisy', None, [ctypes.c_void_p,])
        _icepool_spi_deassert_daisy(self._ctx)
    
    def spi_read_daisy(self, length):
        result = b"\0" * length
        _icepool_spi_read_daisy = _function('icepool_spi_read_daisy', None, [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t,])
        _icepool_spi_read_daisy(self._ctx, result, length)
        return result

    def spi_write_daisy(self, data_out):
        _icepool_spi_write_daisy = _function('icepool_spi_write_daisy', None, [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t,])
        _icepool_spi_write_daisy(self._ctx, data_out, len(data_out))

    def spi_exchange_daisy(self, data_out):
        result = b"\0" * len(data_out)
        _icepool_spi_exchange_daisy = _function('icepool_spi_exchange_daisy', None, [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p, ctypes.c_size_t,])
        _icepool_spi_exchange_daisy(self._ctx, result, data_out, len(data_out))
        return result
    
    def poll_ready(self):
        _icepool_poll_ready = _function('icepool_poll_ready', ctypes.c_bool, [ctypes.c_void_p,])
        return _icepool_poll_ready(self._ctx)
    
    def assert_reset(self):
        _icepool_assert_reset = _function('icepool_assert_reset', None, [ctypes.c_void_p,])
        _icepool_assert_reset(self._ctx)

    def deassert_reset(self):
        _icepool_deassert_reset = _function('icepool_deassert_reset', None, [ctypes.c_void_p,])
        _icepool_deassert_reset(self._ctx)

if __name__ == "__main__":
    context = IcepoolContext()
    print(f'{context}')