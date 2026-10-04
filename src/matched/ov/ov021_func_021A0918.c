/*
 * function: func_021A0918
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
 *   func_0207B65C  0x0207B65C  arm
 *   func_0207BC08  0x0207BC08  arm
 *   func_0207CCA4  0x0207CCA4  arm
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
extern void func_0207B65C(void *o, void *m, s32 a, s32 b);
extern void func_0207BC08(void *m, void *n, void *o);
extern void func_0207CCA4(void *a, void *b);

void func_021A0918(u8 *a, s32 x, s32 y, s16 *out)
{
    s32 m[12];
    s32 v[3];
    s32 vx, vy, vz;
    u32 i;

    i = (u16)(((struct Obj19698 *)a)->f18 * x / y) >> 4;
    func_0207B65C(m, a + 0xc, d_020A1B38[i * 2], d_020A1B38[i * 2 + 1]);
    func_0207BC08(a, m, v);
    func_0207CCA4(v, v);
    vz = v[2];
    vy = v[1];
    vx = v[0];
    out[0] = vx;
    out[1] = vy;
    out[2] = vz;
}
