/*
 * function: FLDMMDL_GetPos
 * address:  0x0216D88C
 * packet:   pkt_ov010_0216D88C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copy an actor's position out (the getter of FLDMMDL_SetPos).
 */

typedef unsigned char u8;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Actor {
    u8 pad00[0x44];
    VecFx32 pos;        /* 0x44 */
} Actor;

void FLDMMDL_GetPos(const Actor *a, VecFx32 *out)
{
    *out = a->pos;
}
