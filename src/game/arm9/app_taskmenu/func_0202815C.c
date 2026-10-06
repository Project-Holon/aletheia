/*
 * function: func_0202815C
 * address:  0x0202815C
 * packet:   pkt_0202815C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x02028164, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * symbols:
 *   func_02028164  0x02028164  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202815C.c \
 *       --func func_0202815C --addr 0x0202815C --thumb --cc 1.1p1
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_02028164(u8 *p);

void func_0202815C(u8 *a0)
{
    func_02028164(a0);
}
