/*
 * function: func_02072E7C
 * address:  0x02072E7C
 * packet:   pkt_02072DE8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02073438  0x02073438  arm
 *
 * HEADER CORRECTED 2026-09-21 (pkt_02072DE8 lane), C unchanged.  The block read
 * `compiler: 1.1p1` / `status: EXACT`, and was neither: under the DEFAULT 1.1p1
 * this source is DIFF at the same 16 bytes (the pool-load-order difference
 * docs/FRONTEND-PINS.md already records for this pair), and under the
 * ../2.0/sp2 pin that same table row names for it, it is MATCH, not EXACT.
 * Both fields now say what match.py actually prints.
 *
 * Blocked at MATCH, evidence class: none available for the sole ABS32 site at
 * +0x0C.  The tail-call target func_02073438 is named by exactly one pool word
 * anywhere in the image -- this function's own, at 0x02072E88 -- so `literal`
 * has no outside witness, `label` does not apply to a pool word, and no
 * `matched` entry covers the address.  A split cannot help: the function is
 * three instructions and the pool word is one of them.
 */

struct Obj_02073438;
extern void func_02073438(struct Obj_02073438 *p, int fadeFrame);

void func_02072E7C(void **r0, int fadeFrame)
{
    func_02073438(*r0, fadeFrame);
}
