/*
 * function: GURU2_RECEIPT_StateWaitMessage
 * address: 0x021DD94C
 * packet: pkt_ov137_021DD94C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * prototype: original r0 holds p at the call to GURU2_RECEIPT_Noop; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 *   GURU2_RECEIPT_IsMessageDone 0x021DE55C thumb ov137
 */
#include "../include/Obj14209.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *p);
extern int GURU2_RECEIPT_IsMessageDone(char *);
int GURU2_RECEIPT_StateWaitMessage(char *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) ((struct Obj14209 *)p)->f118=((struct Obj14209 *)p)->f11C;GURU2_RECEIPT_Noop(p);return state;}
