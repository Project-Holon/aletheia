/*
 * function: func_0202B424
 * address:  0x0202B424
 * packet:   pkt_0202B424
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202B47C, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * symbols:
 *   func_0202B47C  0x0202B47C  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B424.c \
 *       --func func_0202B424 --addr 0x0202B424 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32 func_0202B47C(void);

void func_0202B424(void)
{
    func_0202B47C();
}
