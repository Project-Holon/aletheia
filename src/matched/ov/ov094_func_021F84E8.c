/*
 * function: func_021F84E8
 * address:  0x021F84E8
 * packet:   pkt_ov094_021F84E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_02209318 with the handle at 0x1b0 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_02209318 0x02209318 thumb ov094
 */
extern char *d_0220AF20;
extern void func_02209318(void *, int, int);

void func_021F84E8(int a, int b)
{
    func_02209318(*(void **)(d_0220AF20 + 0x1b0), a, b);
}
