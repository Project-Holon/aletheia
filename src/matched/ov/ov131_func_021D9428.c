/*
 * function: func_021D9428
 * address:  0x021D9428
 * packet:   pkt_021D9428
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D93E4  0x021D93E4  thumb
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int func_021D93E4(unsigned char *);

unsigned int func_021D9428(unsigned char *p)
{
    unsigned int r = func_021D93E4(p);

    if (r < p[0x10])
        return r;
    return 0xffff;
}
