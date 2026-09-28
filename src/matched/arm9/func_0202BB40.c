/*
 * function: func_0202BB40
 * address:  0x0202BB40
 * packet:   pkt_0202B90C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202BA24  0x0202BA24  thumb
 *
 * iss_3ds_sys.c: a bare tail-call thunk to func_0202BA24 (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BA25), the target of the thunk at 0x0202B90C.  Not a
 * seeded start yet (integrator: seed 0x0202BB40 thumb); filed so that
 * func_0202B90C's pool word has a matched witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BB40.c \
 *       --func func_0202BB40 --addr 0x0202BB40 --thumb --cc 1.1p1
 */

typedef unsigned char u8;

extern void func_0202BA24(u8 *p);

void func_0202BB40(u8 *p)
{
    func_0202BA24(p);
}
