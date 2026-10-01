/*
 * function: func_021F84D0
 * address:  0x021F84D0
 * packet:   pkt_ov094_021F84D0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns slot a-8 of the table at 0x1f8 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 */
extern char *d_0220AF20;

int func_021F84D0(int a)
{
    return ((int *)(d_0220AF20 + 0x1f8))[a - 8];
}
