/*
 * function: PMSI_PARAM_Delete
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
 *   GFL_HEAP_Free  0x020307B0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PMSI_PARAM_Delete.c \
 *       --func PMSI_PARAM_Delete --addr 0x020240FC --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32 GFL_HEAP_Free(void *p);

void PMSI_PARAM_Delete(void *t)
{
    GFL_HEAP_Free(t);
}
