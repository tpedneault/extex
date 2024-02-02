#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

using UINT8  = uint8_t;
using UINT16 = uint16_t;
using UINT32 = uint32_t;
using UINT64 = uint64_t;

using INT8   = int8_t;
using INT16  = int16_t;
using INT32  = int32_t;
using INT64  = int64_t;

using CSTR = const char*;

typedef enum { SUCCESS, FAILURE, EINVAL, EIO, ETIMEDOUT } STATUS;

#endif /* TYPES_H */
