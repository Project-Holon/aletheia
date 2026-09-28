/*
 * function: func_02005C28
 * address:  0x02005C28
 * packet:   pkt_02005B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02072794 (arm) reached only by this function's tail call
 *
 * symbols:
 *   func_02072794  0x02072794  arm
 *
 * `func_02072794(a0 != 1)`: the boolean is materialised in place of the
 * parameter (r0), so the fall-through arm carries the literal 1 and the
 * `beq` jumps to the 0.  Writing it as a `v = 1; if (a0 == 1) v = 0;` local
 * makes the compiler allocate a second register and shifts all nine bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02005C28.c \
 *       --func func_02005C28 --addr 0x02005C28 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern void func_02072794(u32 v);

void func_02005C28(u32 a0)
{
    func_02072794(a0 != 1);
}
