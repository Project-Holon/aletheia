/*
 * function: func_02005438
 * address:  0x02005438
 * packet:   pkt_02005438
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  020911A0 (arm) reached only by this file's own pool-word tail call
 *
 * symbols:
 *   func_020911A0  0x020911A0  arm
 *
 * A one-instruction forwarder: `ldr r3, [pc, #0]; bx r3` with the pool word
 * holding the callee.  The word is even, so the callee is ARM - the Thumb
 * tail call of the tail-call idiom, crossing the interworking boundary.  It
 * is four bytes of code plus its own two-word literal pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02005438.c \
 *       --func func_02005438 --addr 0x02005438 --cc 1.1p1 --thumb
 */

extern void func_020911A0(void);

void func_02005438(void)
{
    func_020911A0();
}
