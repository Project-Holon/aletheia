/*
 * function: func_0216446C
 * address:  0x0216446C
 * packet:   pkt_ov010_0216446C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0215E34D);
 * the sole blocker of ov020 func_0218562C.
 *
 * symbols:
 *   func_0215E34C  0x0215E34C  thumb  ov010
 *
 * Every ov020 caller passes a second argument (r1), but func_0215E34C
 * reads only r0, so b stays unused here; its result passes back in r0.
 */

extern int func_0215E34C(int a0);

int func_0216446C(int a, int b)
{
    return func_0215E34C(a);
}
