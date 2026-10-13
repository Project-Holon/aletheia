/*
 * function: ISS_DUNGEON_SYS_Start
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
 *   ISS_DUNGEON_SYS_Activate  0x0202B47C  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_DUNGEON_SYS_Start.c \
 *       --func ISS_DUNGEON_SYS_Start --addr 0x0202B424 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void ISS_DUNGEON_SYS_Activate(u8 *p);

void ISS_DUNGEON_SYS_Start(u8 *a0)
{
    ISS_DUNGEON_SYS_Activate(a0);
}
