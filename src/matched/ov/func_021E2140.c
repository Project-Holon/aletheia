/*
 * function: func_021E2140
 * address:  0x021E2140
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DCFC0  0x021DCFC0  thumb  ov170
 *
 * 8 while busy, else the 0x28 field.
 */



extern int func_021DCFC0(int);
int func_021E2140(int p)
{
    if (func_021DCFC0(p) == 0)
        return *(int *)(p + 0x28);
    return 8;
}
