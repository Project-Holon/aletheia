/*
 * function: func_021CE760
 * address:  0x021CE760
 * packet:   pkt_ov021_021CE760
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u32 func_021CE760(u8 *p)
{
    u32 mask = 0;
    int i;

    for (i = 0; i < 4; i++) {
        if (p[0x70 + i * 0x2c] == 4) {
            mask |= 1 << i;
        }
    }
    return mask;
}
