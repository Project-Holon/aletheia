/*
 * function: func_020240FC
 * address:  0x020240FC
 * packet:   pkt_020240FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x020307B0, the callee's
 * address with its low bit clear, i.e. an ARM target (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * symbols:
 *   sub_020307B0  0x020307B0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020240FC.c \
 *       --func func_020240FC --addr 0x020240FC --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32 sub_020307B0(void *p);

void func_020240FC(void *t)
{
    sub_020307B0(t);
}
