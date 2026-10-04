/*
 * function: func_0202C110
 * address:  0x0202C110
 * packet:   pkt_0202C110
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202C2DC, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * symbols:
 *   sub_0202C2DC  0x0202C2DC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C110.c \
 *       --func func_0202C110 --addr 0x0202C110 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern void sub_0202C2DC(void *p);

void func_0202C110(void *p)
{
    sub_0202C2DC(p);
}
