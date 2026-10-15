/*
 * function: WIFIBATTLEMATCH_UTIL_IsCallbackNull
 * address:  0x021E8A90
 * packet:   pkt_021E8A90
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull   0x021E8A90  thumb ov177
 *
 * Unlabelled ov177 leaf hidden in a word run (it follows WIFIBATTLEMATCH_UTIL_InvokeCallback):
 * loads the word its argument points at and returns 1 when it is zero.
 * Matched to supply the `matched` witness for the four pending callers.
 */

int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **p)
{
    return *p == 0;
}
