/*
 * function: func_021F7F04
 * address:  0x021F7F04
 * packet:   pkt_ov094_021F7F04
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021FF0F8 with the handle at 0x190 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021FF0F8 0x021FF0F8 thumb ov094
 */
extern char *d_0220AF20;
extern void func_021FF0F8(void *, int);

void func_021F7F04(int a)
{
    func_021FF0F8(*(void **)(d_0220AF20 + 0x190), a);
}
