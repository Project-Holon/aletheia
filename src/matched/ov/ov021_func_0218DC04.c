/*
 * function: FIELD_G3D_MAPPER_IsOutsideGrid
 * address:  0x0218DC04
 * packet:   pkt_ov021_0218DC04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled ov021 leaf (a `.word` run in the listing, no lr save), the
 * sole blocker of ov010 FLDMMDL_MOVE_HitCheckMove. Returns 1 (outside) unless the
 * grid is present, not in state 2, and pos.x/pos.z fall inside the
 * w*cell by d*cell rectangle.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Grid {
    u32 f00;
    s32 f04;            /* 0x04 cell size */
    u32 f08;
    u32 f0C;            /* 0x0C state */
    u32 f10;
    u16 f14;            /* 0x14 width in cells */
    u16 f16;            /* 0x16 depth in cells */
    u32 f18;
    void *f1C;          /* 0x1C */
} Grid;

int FIELD_G3D_MAPPER_IsOutsideGrid(Grid *g, VecFx32 *pos)
{
    s32 w;
    s32 d;

    if (g->f1C == 0)
        return 1;
    if (g->f0C == 2)
        return 0;
    w = g->f14 * g->f04;
    d = g->f16 * g->f04;
    if (pos->x >= 0 && pos->x < w && pos->z >= 0 && pos->z < d)
        return 0;
    return 1;
}
