/*
 * function: func_021F50E0
 * address:  0x021F50E0
 * packet:   pkt_021F50E0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_021F50E0(const unsigned char *p)
{
    if (*(const unsigned short *)(p + 6) & 0x200)
        return 1;
    return 0;
}
