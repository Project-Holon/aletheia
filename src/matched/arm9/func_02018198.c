/*
 * function: func_02018198
 * address:  0x02018198
 * packet:   pkt_02018198
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call stub after POKE_TOOL_PushBoxMove (ldr r3, =POKE_TOOL_RecoverBoxAllPP;
 * bx r3). Filed as the witness for ov021 func_021C4340.
 *
 * symbols:
 *   POKE_TOOL_RecoverBoxAllPP  0x020181A0  thumb
 */

extern void POKE_TOOL_RecoverBoxAllPP(void *mon);

void func_02018198(void *mon)
{
    POKE_TOOL_RecoverBoxAllPP(mon);
}
