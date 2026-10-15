/*
 * function: UI_GetSuspendHookGlobal
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
 * src/matched/UI_GetSuspendHook.c) closes the site with no change here.
 *
 * symbols:
 *   gUiState     0x021469BC  data
 *   UI_GetSuspendHook  0x02035100  arm
 */

typedef unsigned int u32;

extern u32  gUiState;
extern u32 UI_GetSuspendHook(u32 *p);

u32 UI_GetSuspendHookGlobal(void)
{
    return UI_GetSuspendHook((u32 *)gUiState);
}
