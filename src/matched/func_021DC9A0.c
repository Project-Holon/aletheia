/*
 * function: func_021DC9A0
 * address:  0x021DC9A0
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
 * Clear the two halfword fields at +0x64/+0x66, store v at +0x58 and zero +0x5c.
 */


void func_021DC9A0(char *p, int v)
{
    *(short *)(p + 0x64) = 0;
    *(short *)(p + 0x66) = 0;
    *(int *)(p + 0x58) = v;
    *(int *)(p + 0x5c) = 0;
}

