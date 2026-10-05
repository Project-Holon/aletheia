/*
 * function: func_02012FA4
 * address:  0x02012FA4
 * packet:   pkt_02012FA4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: stores a byte at +0x1CF.
 */

void func_02012FA4(char *p, char v)
{
    *(char *)(p + 0x1cf) = v;
}
