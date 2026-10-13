/*
 * function: ISS_SWITCH_SYS_On
 * address:  0x0202C0B8
 * packet:   pkt_0202C0B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x0202C1D4, the callee's
 * address with its Thumb bit set (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * symbols:
 *   ISS_SWITCH_SYS_TurnOn  0x0202C1D4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_On.c \
 *       --func ISS_SWITCH_SYS_On --addr 0x0202C0B8 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void ISS_SWITCH_SYS_TurnOn(u8 *p);

void ISS_SWITCH_SYS_On(u8 *a0)
{
    ISS_SWITCH_SYS_TurnOn(a0);
}
