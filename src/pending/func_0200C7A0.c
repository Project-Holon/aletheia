/*
 * function: func_0200C7A0
 * address:  0x0200C7A0
 * packet:   pkt_0200C738
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  0209DE20 - same as func_0200C780: table named only by this function's own pool word.  All 32 bytes right.
 * symbols:
 *   g_0209DE20      0x0209DE20  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 g_0209DE20[];

int func_0200C7A0(u32 v)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (v == g_0209DE20[i])
            return 0;
    }
    return 1;
}
