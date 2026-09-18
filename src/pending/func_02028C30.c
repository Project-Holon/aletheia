/*
 * function: func_02028C30
 * address:  0x02028C30
 * packet:   pkt_02028BDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  0209FDD0 literal
 *
 * symbols:
 *   g_0209FDD0  0x0209FDD0  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 g_0209FDD0[];

int func_02028C30(u16 v)
{
    u32 i = 0;

    while (i < 0x26) {
        if (v == g_0209FDD0[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}
