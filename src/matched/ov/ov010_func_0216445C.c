/*
 * function: func_0216445C
 * address:  0x0216445C
 * packet:   pkt_ov010_0216445C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215E34C  0x0215E34C  thumb  ov010
 *
 * Unlabelled leaf (a tail-call thunk saves nothing, so disasm.py prints it
 * as data after the previous function).  One of four byte-identical thunks
 * to func_0215E34C at 0x02164454, 0x0216445C, 0x02164464 and 0x0216446C.
 * Blocker of ov020 func_021841C0 (case 3 of the *(u8 *)(p + 0x30) switch).
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */

extern int func_0215E34C(int a0);

int func_0216445C(int a, int b)
{
    return func_0215E34C(a);
}
