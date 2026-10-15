/*
 * function: WIFIBATTLEMATCH_UTIL_ClearCallback
 * address:  0x021E8AA8
 * packet:   pkt_021E8AA8
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_ClearCallback   0x021E8AA8  thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback   0x021E8AA0  thumb ov177
 *
 * Unlabelled ov177 thunk hidden in a word run: tail-calls WIFIBATTLEMATCH_UTIL_SetCallback with
 * its second argument zeroed.  Matched to supply the `matched` witness for the
 * pending ov175 caller WIFIBATTLEMATCH_NET_TaskCleanupB.
 */

extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *p, int v);

void WIFIBATTLEMATCH_UTIL_ClearCallback(int a)
{
    WIFIBATTLEMATCH_UTIL_SetCallback((int *)a, 0);
}
