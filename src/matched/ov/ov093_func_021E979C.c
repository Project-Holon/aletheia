/*
 * function: BTLV_CORE_AbortActionMenu
 * address: 0x021E979C
 * packet: pkt_ov093_021E979C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Tail-call thunk to BTLV_CORE_AbortInput (ldr r3 pool, bx r3). Unlabelled leaf filed as the witness for the call in BTL_CLIENT_StepSelectAction.
 * symbols:
 *   BTLV_CORE_AbortActionMenu 0x021E979C thumb ov093
 *   BTLV_CORE_AbortInput 0x021E9928 thumb ov093
 */
extern void BTLV_CORE_AbortInput(char *p);
void BTLV_CORE_AbortActionMenu(char *p) { BTLV_CORE_AbortInput(p); }
