/*
 * function: func_020180F4
 * address:  0x020180F4
 * packet:   pkt_020180F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_PushBoxMove  0x020180FC  thumb
 *
 * An eight-byte Thumb tail thunk: `ldr r3, =POKE_TOOL_PushBoxMove; bx r3` with the
 * pool word immediately after.  It is the only callee of ov121 func_021DEFAC
 * with no `func_` label of its own (disasm.py sees the two-halfword stub as
 * data between POKE_TOOL_PushBoxMove's neighbour and POKE_TOOL_PushBoxMove).  Matching it
 * separately is what lets func_021DEFAC's `bl 0x020180F4` resolve as
 * `matched` rather than wildcarded; the veneer class is ARM-only, so the Thumb
 * stub has no other witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020180F4.c \
 *       --func func_020180F4 --addr 0x020180F4 --cc 1.1p1 --thumb --region arm9
 */

extern void POKE_TOOL_PushBoxMove(void);

void func_020180F4(void *p, int move)
{
    POKE_TOOL_PushBoxMove();
}
