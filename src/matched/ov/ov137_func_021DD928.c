/*
 * function: GURU2_RECEIPT_StateGoToMessage
 * address: 0x021DD928
 * packet: pkt_ov137_021DD928
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
#include "../include/Obj23715.h"
extern void GURU2_RECEIPT_Noop(char *p);
int GURU2_RECEIPT_StateGoToMessage(char *p,int state) {((struct Obj23715 *)p)->f118=2;GURU2_RECEIPT_Noop(p);return state;}
