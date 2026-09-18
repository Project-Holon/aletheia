/*
 * function: func_0202421C
 * address:  0x0202421C
 * packet:   pkt_0202421C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x020355C4, the callee's
 * address with its low bit clear, i.e. an ARM target (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * symbols:
 *   unit_020355C4  0x020355C4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202421C.c \
 *       --func func_0202421C --addr 0x0202421C --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32 unit_020355C4(void);

void func_0202421C(void)
{
    unit_020355C4();
}
