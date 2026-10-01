/*
 * function: func_021F8730
 * address:  0x021F8730
 * packet:   pkt_ov094_021F8730
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the word at 0x1dc of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 */
extern char *d_0220AF20;

int func_021F8730(void)
{
    return *(int *)(d_0220AF20 + 0x1dc);
}
