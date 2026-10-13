/*
 * function: NNS_SndHandlePauseSeq
 * address:  0x02072E8C
 * packet:   pkt_02072DE8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_SndSeqPlayerPause  0x02073484  arm
 *
 * HEADER CORRECTED 2026-09-21 (pkt_02072DE8 lane), C unchanged.  The block read
 * `compiler: 1.1p1` / `status: EXACT`, and was neither: under the DEFAULT 1.1p1
 * this source is DIFF at the same 16 bytes (the pool-load-order difference
 * docs/FRONTEND-PINS.md already records for this pair), and under the
 * ../2.0/sp2 pin that same table row names for it, it is MATCH, not EXACT.
 * Both fields now say what match.py actually prints.
 *
 * Blocked at MATCH, evidence class: none available for the sole ABS32 site at
 * +0x0C.  The tail-call target NNSi_SndSeqPlayerPause is named by exactly one pool word
 * anywhere in the image -- this function's own, at 0x02072E98 -- so `literal`
 * has no outside witness, `label` does not apply to a pool word, and no
 * `matched` entry covers the address.  A split cannot help: the function is
 * three instructions and the pool word is one of them.
 */

extern void NNSi_SndSeqPlayerPause(void *p, unsigned char v);

void NNS_SndHandlePauseSeq(void **r0, unsigned char v)
{
    NNSi_SndSeqPlayerPause(*r0, v);
}
