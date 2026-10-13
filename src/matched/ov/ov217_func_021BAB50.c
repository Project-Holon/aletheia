/*
 * function: func_021BAB50
 * address:  0x021BAB50
 * packet:   pkt_ov217_021BAB50
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_VBlankSystem  0x0204A648  arm
 *
 * Tail-call thunk: ldr r3,[pc,#0]; bx r3; .word 0x0204A648.  Blocker target
 * for func_021BAB58 (pkt_021B9850).
 */

extern void CLACT_VBlankSystem(void);

void func_021BAB50(void)
{
    CLACT_VBlankSystem();
}
