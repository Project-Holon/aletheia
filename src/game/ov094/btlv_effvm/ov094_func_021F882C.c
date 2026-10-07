/*
 * function: func_021F882C
 * address:  0x021F882C
 * packet:   pkt_ov094_021F882C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the word at 0x1f4 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 */
extern char *d_0220AF20;

int func_021F882C(void)
{
    return *(int *)(d_0220AF20 + 0x1f4);
}
