/*
 * function: func_021B9A50
 * address:  0x021B9A50
 * packet:   pkt_021B9A50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B9A5C  0x021B9A5C  thumb  ov093
 */

unsigned char func_021B9A40(unsigned int x);
unsigned char func_021B9A5C(unsigned int x);

unsigned char func_021B9A50(unsigned int x)
{
    return func_021B9A5C(func_021B9A40(x));
}
