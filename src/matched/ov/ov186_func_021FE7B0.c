/*
 * function: BR_FADE_GetResult
 * address:  0x021FE7B0
 * packet:   pkt_021FE7B0
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_FADE_GetResult   0x021FE7B0  thumb ov186
 *
 * Unlabelled ov186 leaf hidden in a word run: loads the word its argument
 * points at.  Matched to supply the `matched` witness for the two pending
 * ov184 callers (func_021F85DC, func_021F8624).
 */

int BR_FADE_GetResult(int *p)
{
    return *p;
}
