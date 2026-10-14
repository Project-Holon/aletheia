/*
 * function: GURU2_RECEIPT_StateReopenRecruit
 * address: 0x021DD970
 * packet: pkt_ov137_021DD970
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
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_Open 0x02184134 thumb ov022
 */
#include "../include/Obj23716.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *p);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern void UNION_APP_Open(u8 *);
int GURU2_RECEIPT_StateReopenRecruit(char *p,int state) {if(GFL_NET_SYSTEM_GetCurrentAid()==0)UNION_APP_Open(GURU2_RECEIPT_GetUnionApp((u8 *)p));((struct Obj23716 *)p)->f118=3;GURU2_RECEIPT_Noop(p);return state;}
