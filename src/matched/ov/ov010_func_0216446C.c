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
 */

void func_0215E34C(void);

void func_0216446C(void)
{
    func_0215E34C();
}
