/*
 * function: GFL_USE_CtrdgDummyInit
 * address:  0x02005438
 * packet:   pkt_02005438
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0004 ABS32 CTRDG_DummyInit          -> unresolved: 020911A0 (arm, from header) has no witness outside 02005438..02005440
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * symbols:
 *   CTRDG_DummyInit  0x020911A0  arm
 *
 * A one-instruction forwarder: `ldr r3, [pc, #0]; bx r3` with the pool word
 * holding the callee.  The word is even, so the callee is ARM - the Thumb
 * tail call of the tail-call idiom, crossing the interworking boundary.  It
 * is four bytes of code plus its own two-word literal pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_CtrdgDummyInit.c \
 *       --func GFL_USE_CtrdgDummyInit --addr 0x02005438 --cc 1.1p1 --thumb
 */

extern void CTRDG_DummyInit(void);

void GFL_USE_CtrdgDummyInit(void)
{
    CTRDG_DummyInit();
}
