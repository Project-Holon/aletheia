/*
 * function: DWCi_IPTlCheckRelease
 * address:  0x021D68A4
 * packet:   pkt_021D68A4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_IPTlCheckRelease 0x021D68A4 arm
 *
 * Gate on the hardware bit, then test the flag word at +0x36 for the whole mask.
 * Addresses are Black-image addresses.
 */

int DWCi_IPTlCheckRelease(unsigned int f)
{
    int *g = (int *)0x021DE688;
    unsigned short v = *(unsigned short *)0x02FFFFA8;

    if ((v & 0x8000) >> 0xf)
        return 0;
    return (f & *(unsigned short *)(g[1] + 0x36)) == f;
}

