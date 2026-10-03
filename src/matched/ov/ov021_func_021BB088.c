/*
 * function: func_021BB088
 * address:  0x021BB088
 * packet:   pkt_ov021_021BB088
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE2C4     0x021DE2C4  data  a4
 */

typedef unsigned short u16;

extern int d_021DE2C4;

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);

void *func_021BB088(int a)
{
    return func_02030734((u16)a, 0x10, 1, (const char *)&d_021DE2C4, 0x5C);
}
