/*
 * function: func_02177BF4
 * address:  0x02177BF4
 * packet:   pkt_ov014_02177BF4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call thunk (ldr r3,[pc]; bx r3) to func_02177BAC.
 * Sole blocker of the func_02164E04 / func_02164D6C MATCHes (ov010).
 *
 * symbols:
 *   func_02177BAC  0x02177BAC  thumb ov014
 *
 * Addresses are Black-image addresses.
 */

extern void func_02177BAC(void);

void func_02177BF4(void)
{
    func_02177BAC();
}
