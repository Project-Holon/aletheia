/*
 * function: ISS_SWITCH_SYS_Off
 * address:  0x0202C0C0
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An eight-byte tail-call thunk into ISS_SWITCH_SYS_TurnOff, with the callee's ISA
 * carried in the low bit of the pool word (docs/idioms/
 * tail-call-is-a-pool-word-and-bx.md).  Unlabelled in the listing and absent
 * from the worklist; filed from the bytes.  src/pending/ISS_SYS_UpdateSwitch.c is
 * blocked on this address and now has it as a `matched` witness.
 *
 * symbols:
 *   ISS_SWITCH_SYS_TurnOff  0x0202C204  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_Off.c \
 *       --func ISS_SWITCH_SYS_Off --addr 0x0202C0C0 --thumb --cc 1.1p1
 */

typedef unsigned int   u32;
extern void ISS_SWITCH_SYS_TurnOff(u32 *p);

void ISS_SWITCH_SYS_Off(u32 *a0)
{
    ISS_SWITCH_SYS_TurnOff(a0);
}
