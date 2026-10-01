/*
 * function: func_021C27A4
 * address:  0x021C27A4
 * packet:   pkt_ov021_021C27A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Saves the four layer priorities into p[0x6C..0x6F].
 */

typedef unsigned char u8;

extern u8 func_020416D4(u8 a);

void func_021C27A4(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++)
        p[0x6C + i] = func_020416D4((u8)i);
}
