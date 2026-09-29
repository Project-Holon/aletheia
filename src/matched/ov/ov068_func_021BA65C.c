/*
 * function: func_021BA65C
 * address:  0x021BA65C
 * packet:   pkt_ov068_021BA65C
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf before func_021BA668; func_021BB1C4 calls it with NULL
 * and with a stack int.
 */

typedef unsigned char u8;

int func_021BA65C(u8 *p, int *out)
{
    if (out != 0)
        *out = *(int *)(p + 0xC);
    return *(int *)(p + 0x10);
}
