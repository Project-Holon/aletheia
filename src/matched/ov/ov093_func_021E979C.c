/*
 * function: func_021E979C
 * address: 0x021E979C
 * packet: pkt_ov093_021E979C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Tail-call thunk to func_021E9928 (ldr r3 pool, bx r3). Unlabelled leaf filed as the witness for the call in BTL_CLIENT_StepSelectAction.
 * symbols:
 *   func_021E979C 0x021E979C thumb ov093
 *   func_021E9928 0x021E9928 thumb ov093
 */
extern void func_021E9928(char *p);
void func_021E979C(char *p) { func_021E9928(p); }
