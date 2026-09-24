/*
 * function: func_021B61B0
 * address:  0x021B61B0
 * packet:   pkt_021B6178
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B61B0   0x021B61B0  thumb
 *   func_021DCE20   0x021DCE20  data
 *
 * FILED EXACT with NO region token on the data symbol.  The `ov016` hint is
 * contested at this address (another overlay mapped over the same window
 * starts an object there).  A contested hint is refused outright by the
 * overlay `sole-ref/data` sub-kind, and for `sole-ref/self` by
 * self_hint_accepted() unless the function itself loads ov016 through an
 * `overlay_id` site -- which this one does not.  Dropping the token leaves
 * the choice to _overlay_pool()'s site_region arm, the region this function
 * is compiled in: it returns the same single overlay, ov016, without taking
 * the refused hint path.  The site then attests `sole-ref/self` -- the ROM
 * word at the pool site already names 0x021DCE20, and 0x021DCE20 is data in exactly one
 * overlay of the pool.  See scratch/ov_ov016/o27/report.md.
 *
 * Forward the argument a to the handler in the global function pointer at 0x021DCE20.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B61B0.c \
 *       --func func_021B61B0 --addr 0x021B61B0 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void (*func_021DCE20)(int);

void func_021B61B0(int a)
{
    func_021DCE20(a);
}
