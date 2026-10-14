/*
 * function: GURU2_RECEIPT_SendMemberCount
 * address: 0x021DCF58
 * packet: pkt_ov137_021DCF58
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 */
#include "../include/Obj23705.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GURU2_COMM_Send(void *p, u32 a, const void *b, u32 c);
void GURU2_RECEIPT_SendMemberCount(int a,int b,u8 *p) {u8 v;if(GFL_NET_SYSTEM_GetCurrentAid()==0) {v=a;GURU2_COMM_Send(((struct Obj23705 *)p)->f10,10240,&v,1);}}
