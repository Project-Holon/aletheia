#ifndef FIELD_3DBG_TYPES_H
#define FIELD_3DBG_TYPES_H

/* Billboard layers drawn by field_3dbg.c; weather.c owns two of them. */

#include "../types.h"

#include "../sdk_fx.h"

/* Static description of one billboard (12 bytes per table entry). */
typedef struct Field3dbgBillboardDesc {
    u16 width;
    u16 height;
    u32 distance;
    u8 polygonId;
} Field3dbgBillboardDesc;

/* Static description of one billboard texture. */
typedef struct Field3dbgTextureDesc {
    u16 fileId;
    u8 sizeS;
    u8 sizeT;
    u8 repeat;
    u8 flip;
    u8 format;
    u8 plttColor0;
    u8 alpha;
} Field3dbgTextureDesc;

/* A texture loaded for a billboard. */
typedef struct Field3dbgTexture {
    u8 sizeS;
    u8 sizeT;
    u8 repeat;
    u8 flip;
    u8 format;
    u8 plttColor0;
    u8 isLoaded;
    u8 isResident;
    void *resource;
} Field3dbgTexture;

/* Quad extents and texture window computed from a billboard and the projection. */
typedef struct Field3dbgQuadGeometry {
    fx32 halfWidth;
    fx32 halfHeight;
    fx32 depth;
    fx32 scale;
    fx32 texS0;
    fx32 texS1;
    fx32 texT0;
    fx32 texT1;
    MtxFx33 rotation;
} Field3dbgQuadGeometry;

/* One textured quad drawn in 3D space (a weather particle layer). */
typedef struct Field3dbgBillboard {
    u16 width;
    u16 height;
    fx32 distance;
    u32 isVisible;
    fx32 texOffsetX;
    fx32 texOffsetY;
    fx32 scaleX;
    fx32 scaleY;
    u16 rotation;
    u8 polygonId;
    u8 alpha;
    Field3dbgTexture tex;
    Field3dbgQuadGeometry geom;
} Field3dbgBillboard;

#endif
