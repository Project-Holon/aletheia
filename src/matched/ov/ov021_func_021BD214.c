/*
 * function: func_021BD214
 * address:  0x021BD214
 * packet:   pkt_ov021_021BD214
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE368     0x021DE368  data  a4
 */

extern int d_021DE368;

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);

void *func_021BD214(int a)
{
    return func_02030734(a, 0x4C, 0, (const char *)&d_021DE368, 0x170);
}
