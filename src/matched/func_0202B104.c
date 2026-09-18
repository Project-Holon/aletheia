/*
 * function: func_0202B104
 * address:  0x0202B104
 * packet:   pkt_0202AF74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202B174  0x0202B174  thumb
 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 func_0202B174(u8 *a0);

u32 func_0202B104(u8 *a0, s32 *a1)
{
    s32 i;
    s32 v = a1[2] >> 12;
    s32 d = v - func_0202B174(a0);

    if (d < 0) d = -d;
    for (i = 0; i < 6; i++) {
        if ((a0[i + 0x22] << 4) <= d) return (u8)i;
    }
    return 0;
}
