/*
 * function: func_021F8774
 * address:  0x021F8774
 * packet:   pkt_ov094_021F8774
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_022088F4 with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_022088F4 0x022088F4 thumb ov094
 */
extern char *d_0220AF20;
extern void func_022088F4(void *);

void func_021F8774(void)
{
    func_022088F4(*(void **)(d_0220AF20 + 0x1a4));
}
