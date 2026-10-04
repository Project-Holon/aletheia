/*
 * function: func_021BC7F0
 * address:  0x021BC7F0
 * packet:   pkt_021BC52C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC7F0   0x021BC7F0  thumb
 *   func_021DD13C   0x021DD13C  data
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
 * word at the pool site already names 0x021DD13C, and 0x021DD13C is data in exactly one
 * overlay of the pool.  See scratch/ov_ov016/o27/report.md.
 *
 * Fill 0xe8 bytes of the 0x021DD13C buffer, then report success.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021BC7F0.c \
 *       --func func_021BC7F0 --addr 0x021BC7F0 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern char func_021DD13C[];

int func_021BC7F0(int a)
{
    func_02092344((void *)a, func_021DD13C, 0xe8);
    return 1;
}
