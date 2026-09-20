/*
 * function: func_0200C780
 * address:  0x0200C780
 * packet:   pkt_0200C738
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  0209DE2C - data table named by one pool word in the whole image, this function's own; the `literal` class discards its only witness and no cut helps.  All 32 bytes right.
 * symbols:
 *   g_0209DE2C      0x0209DE2C  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 g_0209DE2C[];

int func_0200C780(u32 v)
{
    u32 i;

    for (i = 0; i < 0xf; i++) {
        if (v == g_0209DE2C[i])
            return 0;
    }
    return 1;
}
