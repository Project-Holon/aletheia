/*
 * function: func_021C5380
 * address:  0x021C5380
 * packet:   pkt_ov021_021C5380
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 1 in states 2 and 5.
 */

typedef unsigned char u8;
typedef unsigned short u16;

int func_021C5380(u8 *p)
{
    int r = 1;

    if (*(u16 *)(p + 0x70) != 2 && *(u16 *)(p + 0x70) != 5)
        r = 0;
    return r;
}
