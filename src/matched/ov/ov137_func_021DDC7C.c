/*
 * function: GURU2_RECEIPT_StateSendStartRequest
 * address: 0x021DDC7C
 * packet: pkt_ov137_021DDC7C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original cmp r0,#1 at 021DDC96 uses GURU2_COMM_Send's return;
 * retain int return despite the pending void tail-forwarder. Original 021DDCA2
 * supplies r0=1 to GFL_NET_SetLoginOption despite its filed no-argument prototype.
 * symbols:
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GURU2_RECEIPT_Noop  0x021DD924  thumb
 */
#include "../include/Obj10617.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *p);
extern int GURU2_COMM_Send(void *,u32,const void *,u32);
extern void GFL_NET_SetLoginOption(u8 a0);
int GURU2_RECEIPT_StateSendStartRequest(char *p,int state) {if(((struct Obj10617 *)p)->f4813==0) {if(GURU2_COMM_Send(((struct Obj10617 *)p)->f10,0x2804,0,0)==1) {((struct Obj10617 *)p)->f118=27;GFL_NET_SetLoginOption(1);}}return state;}
