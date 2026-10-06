/*
 * function: func_021C6C94
 * address:  0x021C6C94
 * packet:   pkt_021C6C94
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201EFA4  0x0201EFA4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct WordSet;
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

void func_021C6C94(char **p, int a)
{
    func_0201EFA4((struct WordSet *)(*p), 0, a, 4, 1, 1);
}
