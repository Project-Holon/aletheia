/*
 * function: func_021C9858
 * address:  0x021C9858
 * packet:   pkt_ov114_021C9858
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      b64size (dwc_encsession.o)
 *
 * symbols:
 */

unsigned long func_021C9858(unsigned long len)
{
    return (len / 3 + (len % 3 != 0 ? 1 : 0)) * 4;
}
