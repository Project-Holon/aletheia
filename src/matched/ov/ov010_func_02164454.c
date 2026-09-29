/*
 * function: func_02164454
 * address:  0x02164454
 * packet:   pkt_ov010_02164454
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
 * Blocker of ov020 func_021841C0 (case 1 of the *(u8 *)(p + 0x30) switch).
 */

extern void func_0215E34C(int a, int b);

void func_02164454(int a, int b)
{
    func_0215E34C(a, b);
}
