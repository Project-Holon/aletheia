/*
 * function: func_021BC40C
 * address:  0x021BC40C
 * packet:   pkt_021BC40C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC6DC  0x021BC6DC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int func_021BC6DC(void *p);

int func_021BC40C(void *p)
{
    return (int)func_021BC6DC(p) * 0x18 - 0xa8;
}
