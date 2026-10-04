/*
 * function: func_021F2CD8
 * address:  0x021F2CD8
 * packet:   pkt_ov029_021F2CD8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

void func_021F2CD8(char *p)
{
    if (*(u8 *)(p + 0x45C) == 0) {
        *(u8 *)(p + 0x45C) = 1;
        *(u8 *)(p + 0x45E) = 1;
        *(u8 *)(p + 0x45F) = 0;
    }
}
