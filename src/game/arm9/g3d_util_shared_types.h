#ifndef G3D_UTIL_SHARED_TYPES_H
#define G3D_UTIL_SHARED_TYPES_H

struct ArcHandle;

#include "../types.h"

struct ArcHandle {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

#endif
