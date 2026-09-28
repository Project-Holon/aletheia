/*
 * function: func_021C0C00
 * address:  0x021C0C00
 * packet:   pkt_021C0C00
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 *
 * Calls 0x0204B3B4 on the second argument, then 0x0204A8D4 on the first.
 */

extern void func_0204B3B4(void *);
extern void func_0204A8D4(void *);

void func_021C0C00(void *a, void *b)
{
    func_0204B3B4(b);
    func_0204A8D4(a);
}
