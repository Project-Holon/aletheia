#ifndef SHINKA_DEMO_GRAPHIC_SHARED_TYPES_H
#define SHINKA_DEMO_GRAPHIC_SHARED_TYPES_H

struct ShinkaDemoGraphicNode;

struct Light;

#include "../types.h"

typedef struct ShinkaDemoGraphicNode {
    u16 id;
    u16 pad02;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u8 mtx[0x24];
    u8 pad40[4];
} ShinkaDemoGraphicNode;

#endif
