/*
 * function: func_021C08A8
 * address:  0x021C08A8
 * packet:   pkt_021C08A8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern int func_021C2A08(char *p);

void func_021C08A8(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C2A08((char *)p[i + 0xC9]);
}
