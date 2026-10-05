/*
 * function: func_021B1588
 * address: 0x021B1588
 * packet: pkt_ov013_021B1588
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * note: 2026-10-05 tried forms (all DIFF 26/172): an inline encode() with an
 *   inline seg_search() helper, mask types and orders, clamp spellings,
 *   pragmas opt_lifetimes, scheduling, peephole, opt_common_subs,
 *   opt_propagation, opt_dead_assignments, opt_dead_code,
 *   opt_strength_reduction, opt_loop_invariants.
 * note: pass 2 2026-10-06 P2L37: EXACT. The u-law encode is written in the
 *   loop body (no inline helpers). The segment search uses seg as its own
 *   counter, with a goto on a hit and seg = 8 on fall-through, as the helper's
 *   "return size". The code value goes through an int uval and the store is
 *   dst[i] = uval ^ mask. With the inline helpers, the mask and the segment
 *   counter swapped registers (r5/r6).
 * symbols:
 *   d_021B3C28 0x021B3C28 data a4
 */
extern const int d_021B3C28[8];

void func_021B1588(unsigned char *dst, const short *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++) {
        int s, seg, uval;
        unsigned char mask;
        const int *tab;

        s = src[i] >> 2;
        if (s < 0) {
            mask = 0x7f;
            s = -s;
        } else {
            mask = 0xff;
        }
        if (s > 8159)
            s = 8159;
        tab = d_021B3C28;
        for (seg = 0; seg < 8; seg++)
            if (s + 0x21 <= *tab++)
                goto found;
        seg = 8;
    found:
        if (seg >= 8) {
            dst[i] = 0x7f ^ mask;
        } else {
            uval = (seg << 4) | (((s + 0x21) >> (seg + 1)) & 0xf);
            dst[i] = uval ^ mask;
        }
    }
}
