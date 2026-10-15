/*
 * function: WIFIBATTLEMATCH_GRAPHIC_GetCamera
 * address:  0x021E5548
 * packet:   pkt_021E5548
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera   0x021E5548  thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_GetClactBank   0x021E5678  thumb ov177
 *
 * Unlabelled ov177 thunk hidden in a word run: tail-calls WIFIBATTLEMATCH_GRAPHIC_GetClactBank with
 * its pointer argument advanced by one word.  Matched to supply the `matched`
 * witness for the pending ov176 caller BATTLE_CHAMPIONSHIP_FLOW_CreateView.
 */

extern int WIFIBATTLEMATCH_GRAPHIC_GetClactBank(int *);

int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *p)
{
    return WIFIBATTLEMATCH_GRAPHIC_GetClactBank(p + 1);
}
