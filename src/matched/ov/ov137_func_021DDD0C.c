/*
 * function: GURU2_RECEIPT_StateWaitEndWipe
 * address: 0x021DDD0C
 * packet: pkt_ov137_021DDD0C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj23724.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *p);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
int GURU2_RECEIPT_StateWaitEndWipe(char *p,int state) {if(++((struct Obj23724 *)p)->f124>60) {WIPE_SYS_Start(0,0,0,0,16,1,114);state=3;}GURU2_RECEIPT_Noop(p);return state;}
