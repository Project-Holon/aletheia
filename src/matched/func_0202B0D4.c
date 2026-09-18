/*
 * function: func_0202B0D4
 * address:  0x0202B0D4
 * packet:   pkt_0202AF74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202B154  0x0202B154  thumb
 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 func_0202B154(u8 *a0);

u32 func_0202B0D4(u8 *a0, s32 *a1)
{
    s32 i;
    s32 v = a1[1] >> 12;
    s32 d = v - func_0202B154(a0);

    if (d < 0) d = -d;
    for (i = 0; i < 6; i++) {
        if ((a0[i + 0x1c] << 4) <= d) return (u8)i;
    }
    return 0;
}
