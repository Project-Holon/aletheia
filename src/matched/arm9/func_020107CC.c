/*
 * function: WIH_DWC_ResetFilterState
 * address:  0x020107CC
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWihDwc        0x021461E0  data
 *   sWihDwcAssertArg           0x020A7240  data
 *   func_02034714     0x02034714  arm
 *   func_0205FAA8     0x0205FAA8  arm
 *
 * wih_dwc.c: the sibling of WIH_DWC_CreateFilterBuffer in the same packet - same guard on
 * the +0x04 field of the object at 0x021461E0, same file-name call, and the
 * field is re-read afterwards (a second pool load), so the callee is allowed
 * to have set it.  The tail is func_0205FAA8(f4 + 0x600, 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_ResetFilterState.c \
 *       --func WIH_DWC_ResetFilterState --addr 0x020107CC --cc 1.1p1 --thumb
 *
 * blocker:  label.  The tail call at +0x20 targets 0x0205FAA8 (ARM, so BLX)
 *           and no branch anywhere else in the image reaches that address -
 *           this function is its only caller - so the site has no witness
 *           outside the compared range and no cut can give it one (shrinking
 *           the range to this one function keeps the call inside it).  The
 *           target is not in an EXACT manifest entry either, so the `matched`
 *           class does not reach it.  Byte-correct as it stands.
 */

#include "../include/G_WihCtx.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct WihCtx gWihDwc;
extern u8 sWihDwcAssertArg;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0205FAA8(u8 *p, u32 v);

void WIH_DWC_ResetFilterState(void)
{
    if (gWihDwc.f4 == 0) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    func_0205FAA8(((u8 *)gWihDwc.f4) + 0x600, 0);
}
