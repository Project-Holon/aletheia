/*
 * function: func_021BCF88
 * address:  0x021BCF88
 * packet:   pkt_ov021_021BCF88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE354     0x021DE354  data  a4
 */

extern int d_021DE354;

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);

void *func_021BCF88(int a)
{
    return func_02030734(a, 0x154, 1, (const char *)&d_021DE354, 0x73C);
}
