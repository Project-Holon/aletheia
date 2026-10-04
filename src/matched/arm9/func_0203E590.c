/*
 * function: func_0203E590
 * address:  0x0203E590
 * packet:   pkt_0203E590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   d_021469F0 0x021469F0 data a4
 *
 * Reads byte 0x108 of the singleton, or 0 when it is not allocated.
 */
extern unsigned char *d_021469F0;
int func_0203E590(void)
{
    unsigned char *p = d_021469F0;
    if (p == 0) return 0;
    return p[0x108];
}
