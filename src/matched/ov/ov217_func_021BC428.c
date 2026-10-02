/*
 * function: func_021BC428
 * address:  0x021BC428
 * packet:   pkt_021BC428
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

int func_021BC428(void *p)
{
    return (int)func_021BC6DC(p) * 0x18 > 0x90;
}
