/*
 * function: DWCi_IPTlCheckRepeat
 * address:  0x021D6864
 * packet:   pkt_021D6864
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_IPTlCheckRepeat 0x021D6864 arm
 *
 * Gate on the hardware bit, then test the flag word at +0x34 for the whole mask.
 * Addresses are Black-image addresses.
 */

int DWCi_IPTlCheckRepeat(unsigned int f)
{
    int *g = (int *)0x021DE688;
    unsigned short v = *(unsigned short *)0x02FFFFA8;

    if ((v & 0x8000) >> 0xf)
        return 0;
    return (f & *(unsigned short *)(g[1] + 0x34)) == f;
}

