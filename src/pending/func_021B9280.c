/*
 * function: func_021B9280
 * address:  0x021B9280
 * packet:   pkt_021B9280
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * near miss: compiles 180 vs 184.  Logic byte-correct; sC/s8 stack slots and
 * the `num` destination register differ (the original keeps num in r1).
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
    int sC = -1;
    int s8 = -1;
    int num;
    int i;

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
        num = (int)(arg2 * (u32)num) / (int)(arg3 - 0x10);
    return sC + num;
}
