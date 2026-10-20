#ifndef G3D_UTIL_SHARED_TYPES_H
#define G3D_UTIL_SHARED_TYPES_H

struct ArcHandle;

#include "../types.h"
#include "../sdk_fs.h"

struct ArcHandle {
    FSFile file;
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

#endif
