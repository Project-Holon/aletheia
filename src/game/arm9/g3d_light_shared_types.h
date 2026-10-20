#ifndef G3D_LIGHT_SHARED_TYPES_H
#define G3D_LIGHT_SHARED_TYPES_H

#include "../arm9/g3d_util_shared_types.h"

struct ArcTableInfo {
    u32 * volatile entries;
    u32  count;
    u32  useRecords;
};

#endif
