/*
 * function: WIFIBATTLEMATCH_VIEW_UpdatePokeList
 * address:  0x021E64C0
 * packet:   pkt_021E64C0
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList   0x021E64C0  thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateWindow   0x021E6E8C  thumb ov177
 *
 * Unlabelled ov177 thunk hidden in a word run: forwards to WIFIBATTLEMATCH_VIEW_UpdateWindow.
 * Matched to supply the `matched` witness for the pending ov176 caller
 * DIGITALCARDCHECK_DeleteAlt.
 */

extern int WIFIBATTLEMATCH_VIEW_UpdateWindow(unsigned char *p, void *mgr);

int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *p, void *mgr)
{
    return WIFIBATTLEMATCH_VIEW_UpdateWindow(p, mgr);
}
