/*
 * function: GURU2_RECEIPT_StateResetWait
 * address: 0x021DDAEC
 * packet: pkt_ov137_021DDAEC
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
#include "../include/Obj23719.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *p);
int GURU2_RECEIPT_StateResetWait(char *p,int state) {((struct Obj23719 *)p)->f4820=0;GURU2_RECEIPT_Noop(p);return state;}
