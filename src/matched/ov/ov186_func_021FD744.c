/*
 * function: BR_UTIL_ClearTaskStep
 * address:  0x021FD744
 * packet:   pkt_021FD744
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_UTIL_ClearTaskStep   0x021FD744  thumb ov186
 *   BR_UTIL_SetTaskStep   0x021FD73C  thumb ov186
 *
 * Unlabelled ov186 thunk hidden in a word run: tail-calls BR_UTIL_SetTaskStep with
 * the second argument zeroed.  Matched to supply the `matched` witness for the
 * pending caller func_021F8624.
 */

extern int *BR_UTIL_SetTaskStep(int *p, int v);

int BR_UTIL_ClearTaskStep(int *a)
{
    return (int)BR_UTIL_SetTaskStep(a, 0);
}
