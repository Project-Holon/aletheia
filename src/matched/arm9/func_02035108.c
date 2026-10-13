/*
 * function: func_02035108
 * address:  0x02035108
 * packet:   pkt_0203508C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * closed:   the tail call's target 0x02035100 is now a manifest entry
 *           (matched class); the global resolves on `literal x100`.
 *
 * Promoted out of src/pending: it was parked at MATCH on 0x02035100, an
 * unlabelled eight-byte leaf that had no witness of any class - its only
 * naming pool word is this function's own.  Filing the leaf (see
 * src/matched/func_02035100.c) closes the site with no change here.
 *
 * symbols:
 *   gUiState     0x021469BC  data
 *   func_02035100  0x02035100  arm
 */

typedef unsigned int u32;

extern u32  gUiState;
extern u32 func_02035100(u32 *p);

u32 func_02035108(void)
{
    return func_02035100((u32 *)gUiState);
}
