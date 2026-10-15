#ifndef SHINKA_DEMO_VIEW_SHARED_TYPES_H
#define SHINKA_DEMO_VIEW_SHARED_TYPES_H

#include "shinka_demo_graphic_shared_types.h"

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct MtxFx33 {
    fx32 m[3][3];
} MtxFx33;

#endif
