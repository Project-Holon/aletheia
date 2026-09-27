/*
 * function: func_021DFBF0
 * address:  0x021DFBF0
 * packet:   pkt_ov119_021DFBF0
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of the parked ov119 func_021DFC68
 * (+0044) and part of the func_021D7130 tree.  Interpolates between a0 and a1
 * at record stride (the difference divided by f04, scaled by f08), then, when
 * the record's f16 is set and a3 is nonzero, re-derives the position from the
 * sine table tbl_020A1B38 with the phase f14>>4.  The divide's destination
 * only reproduces when the quotient is bound to its own local first
 * (`int q = ...; int r = q * a2->f08 + a0;`).
 *
 * symbols:
 *   _s32_div_f      0x0209C0A4  arm
 *   tbl_020A1B38    0x020A1B38  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern s32 _s32_div_f(s32, s32);
extern s16 tbl_020A1B38[];

typedef struct {
    u32 f00;
    s32 f04;
    s32 f08;
    u32 f0c;
    u32 f10;
    u16 f14;
    u16 f16;
} S;

int func_021DFBF0(int a0, int a1, S *a2, int a3)
{
    int q = (a1 - a0) / a2->f04;
    int r = q * a2->f08 + a0;

    if (a2->f16 != 0 && a3 != 0)
        r = a1 + tbl_020A1B38[2 * (a2->f14 >> 4)] * 8;
    return r;
}
