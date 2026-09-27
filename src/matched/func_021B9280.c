/*
 * function: func_021B9280
 * address:  0x021B9280
 * packet:   pkt_021B9280
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two stride-0x70 rows selected by a->f0 / a->f4; for each of four columns
 * look the referenced 0x48-row up in the tbl tables and keep its +0x20 field
 * in sC (row1) / s8 (row2).  Missing entries fall back to the other row.
 * Then clamp arg2 to arg3-0x10 and interpolate: sC + num*(s8-sC)/(arg3-0x10).
 *
 * Matching notes (dependency-tree lane, 2026-09-27):
 *   - the multiplication must read `num * arg2` (num in r1, arg2 in r0), and
 *     the return `num + sC` (adds r0,r1,r0) -- commutative operand order.
 *   - sC/s8 must be *declared* in that order (sC gets [sp,#0xc], s8 [sp,#8])
 *     but *assigned* `s8 = -1; sC = -1;` so the two -1 stores land on [sp,#8]
 *     then [sp,#0xc], reusing the 0x70 multiply temp's slot.  Initialising at
 *     the declaration produces the reversed store order (25-byte diff).
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl)
{
    u8 *row1 = *(u8 **)(tbl + 0x10) + *(u32 *)a * 0x70;
    u8 *row2 = *(u8 **)(tbl + 0x10) + *(u32 *)(a + 4) * 0x70;
    int sC;
    int s8;
    int num;
    int i;

    s8 = -1;
    sC = -1;
    for (i = 0; i < 4; i++) {
        u32 v1 = *(u32 *)(row1 + i * 4);
        if (v1 != 0xFFFF) {
            if (a == *(u8 **)(tbl + 0x14) + v1 * 0x48)
                sC = *(int *)(row1 + i * 4 + 0x20);
        }
        {
            u32 v2 = *(u32 *)(row2 + i * 4);
            if (v2 != 0xFFFF) {
                if (a == *(u8 **)(tbl + 0x14) + v2 * 0x48)
                    s8 = *(int *)(row2 + i * 4 + 0x20);
            }
        }
    }
    if (sC < 0)
        sC = s8;
    if (s8 < 0)
        s8 = sC;
    if (arg2 > arg3 - 0x10)
        arg2 = arg3 - 0x10;
    num = s8 - sC;
    if (arg3 - 0x10 != 0)
        num = (int)((u32)num * arg2) / (int)(arg3 - 0x10);
    return num + sC;
}
