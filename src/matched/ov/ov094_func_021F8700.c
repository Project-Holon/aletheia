/*
 * function: func_021F8700
 * address:  0x021F8700
 * packet:   pkt_ov094_021F8700
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the word at 0x1b4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 */
extern char *d_0220AF20;

int func_021F8700(void)
{
    return *(int *)(d_0220AF20 + 0x1b4);
}
