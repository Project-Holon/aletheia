/*
 * function: func_020107CC
 * address:  0x020107CC
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   g_021461E0        0x021461E0  data
 *   sWihDwc           0x020A7240  data
 *   func_02034714     0x02034714  arm
 *   func_0205FAA8     0x0205FAA8  arm
 *
 * wih_dwc.c: the sibling of func_02010794 in the same packet - same guard on
 * the +0x04 field of the object at 0x021461E0, same file-name call, and the
 * field is re-read afterwards (a second pool load), so the callee is allowed
 * to have set it.  The tail is func_0205FAA8(f4 + 0x600, 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020107CC.c \
 *       --func func_020107CC --addr 0x020107CC --cc 1.1p1 --thumb
 *
 * blocker:  label.  The tail call at +0x20 targets 0x0205FAA8 (ARM, so BLX)
 *           and no branch anywhere else in the image reaches that address -
 *           this function is its only caller - so the site has no witness
 *           outside the compared range and no cut can give it one (shrinking
 *           the range to this one function keeps the call inside it).  The
 *           target is not in an EXACT manifest entry either, so the `matched`
 *           class does not reach it.  Byte-correct as it stands.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct WihCtx {
    u8 *f0;         /* +0x00 */
    u8 *f4;         /* +0x04 */
};

extern struct WihCtx g_021461E0;
extern u8 sWihDwc;

extern void func_02034714(void *dst, u32 val, void *dst2);
extern void func_0205FAA8(u8 *p, u32 v);

void func_020107CC(void)
{
    if (g_021461E0.f4 == 0) {
        func_02034714(&sWihDwc, 0, &sWihDwc);
    }
    func_0205FAA8(g_021461E0.f4 + 0x600, 0);
}
