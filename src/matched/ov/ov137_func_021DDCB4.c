/*
 * function: GURU2_RECEIPT_StateWaitStartReady
 * address: 0x021DDCB4
 * packet: pkt_ov137_021DDCB4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   GURU2_RECEIPT_Noop  0x021DD924  thumb
 */
#include "../include/Obj14213.h"
#include "../include/Obj23723.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *p);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern int UNION_APP_GetMemberCount(u8 *);
int GURU2_RECEIPT_StateWaitStartReady(char *p,int state) {if(GFL_NET_SYSTEM_GetCurrentAid()==0)UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p));if(((struct Obj23723 *)(*(char * *)&((struct Obj14213 *)p)->f10))->f20==UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p))) ((struct Obj14213 *)p)->f118=27;return state;}
