/*
 * function: FIELD_LIGHT_EvalDirLerp
 * address:  0x021A0918
 * packet:   pkt_ov021_021A0918
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   MTX_RotAxis43  0x0207B65C  arm
 *   MTX_MultVec43  0x0207BC08  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   d_020A1B38  0x020A1B38  data  a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19698.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern s16 d_020A1B38[];
extern void MTX_RotAxis43(void *o, void *m, s32 a, s32 b);
extern void MTX_MultVec43(void *m, void *n, void *o);
extern void VEC_Normalize(void *a, void *b);

void FIELD_LIGHT_EvalDirLerp(u8 *a, s32 x, s32 y, s16 *out)
{
    s32 m[12];
    s32 v[3];
    s32 vx, vy, vz;
    u32 i;

    i = (u16)(((struct Obj19698 *)a)->f18 * x / y) >> 4;
    MTX_RotAxis43(m, a + 0xc, d_020A1B38[i * 2], d_020A1B38[i * 2 + 1]);
    MTX_MultVec43(a, m, v);
    VEC_Normalize(v, v);
    vz = v[2];
    vy = v[1];
    vx = v[0];
    out[0] = vx;
    out[1] = vy;
    out[2] = vz;
}
