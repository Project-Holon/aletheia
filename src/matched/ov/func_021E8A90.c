/*
 * function: func_021E8A90
 * address:  0x021E8A90
 * packet:   pkt_021E8A90
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8A90   0x021E8A90  thumb ov177
 *
 * Unlabelled ov177 leaf hidden in a word run (it follows func_021E8A80):
 * loads the word its argument points at and returns 1 when it is zero.
 * Matched to supply the `matched` witness for the four pending callers.
 */

int func_021E8A90(int **p)
{
    return *p == 0;
}
