/*
 * function: GURU2_RECEIPT_StateAnswersDone
 * address: 0x021DDB90
 * packet: pkt_ov137_021DDB90
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 *   GURU2_RECEIPT_SetPendingState 0x021DD93C thumb ov137
 */
#include "../include/Obj23722.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *p);
extern void GURU2_RECEIPT_SetPendingState(char *,int);
int GURU2_RECEIPT_StateAnswersDone(char *p,int state) {((struct Obj23722 *)p)->f4810=0;GURU2_RECEIPT_SetPendingState(p,0);GURU2_RECEIPT_Noop(p);return state;}
