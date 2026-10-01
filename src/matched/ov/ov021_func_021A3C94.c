/*
 * function: func_021A3C94
 * address:  0x021A3C94
 * packet:   pkt_ov021_021A3C94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned int u32;

int func_021A3C94(u32 x)
{
    int i = 10;

    if (x != 0) {
        for (i = 0; i < 10; i++) {
            if (x & 1)
                break;
            x >>= 1;
        }
    }
    return i;
}
