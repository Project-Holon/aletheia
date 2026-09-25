/*
 * function: func_021DE6F8
 * address:  0x021DE6F8
 * packet:   pkt_021DE6F8
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02010498  0x02010498  thumb
 *   func_0201058C  0x0201058C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_02010498(int, int, void *);
extern int func_0201058C(int);

void func_021DE6F8(int a, int b, char *c)
{
    func_02010498(a, b, c);
    *(u32 *)(c + 0x54) = func_0201058C(0);
}
