/*
 * function: func_021F8740
 * address:  0x021F8740
 * packet:   pkt_ov094_021F8740
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns halfword a of the table at 0x1d4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 */
extern char *d_0220AF20;

unsigned short func_021F8740(int a)
{
    return ((unsigned short *)(d_0220AF20 + 0x1d4))[a];
}
