/*
 * function: func_021F8198
 * address:  0x021F8198
 * packet:   pkt_ov094_021F8198
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_02207CC4 with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_02207CC4 0x02207CC4 thumb ov094
 */
extern char *d_0220AF20;
struct O;
extern void func_02207CC4(struct O *obj, int a, int c);

void func_021F8198(int a, int b)
{
    func_02207CC4(*(void **)(d_0220AF20 + 0x1a4), a, b);
}
