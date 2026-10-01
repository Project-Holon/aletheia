/*
 * function: func_021F8168
 * address:  0x021F8168
 * packet:   pkt_ov094_021F8168
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_022089AC with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_022089AC 0x022089AC thumb ov094
 */
extern char *d_0220AF20;
extern void func_022089AC(void *);

void func_021F8168(void)
{
    func_022089AC(*(void **)(d_0220AF20 + 0x1a4));
}
