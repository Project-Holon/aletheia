/*
 * function: func_021E8FE0
 * address:  0x021E8FE0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Store v at +0x28, return 13.
 */


int func_021E8FE0(char *p, int v)
{
    *(int *)(p + 0x28) = v;
    return 0xd;
}

