/*
 * function: POKETRADE_PROC_StartRequest1
 * address: 0x021DCAD4
 * packet: pkt_ov119_021DCAD4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_AllocTradeWork 0x021DC854 thumb ov119
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GAME_DATA_GetPlayerStatus 0x02012950 thumb
 *   POKETRADE_PROC_InitTradeWork 0x021DC894 thumb ov119
 */
#include "../include/Obj03256.h"
#include "../include/Obj04478.h"
#include "../include/Obj13894.h"
extern void *POKETRADE_PROC_AllocTradeWork(void *a, int t); extern int GFL_NET_SYSTEM_GetCurrentAid(void); extern int GAME_DATA_GetPlayerStatus(int,int); extern void POKETRADE_PROC_InitTradeWork(void *,int,void *,void *,int);
void POKETRADE_PROC_StartRequest1(void *a,int b,char *c) {char *p=POKETRADE_PROC_AllocTradeWork(a,0xc6000);int i; for(i=0;i<2;i++) {char *d=p+i*4;((struct Obj13894 *)d)->f1048=0;((struct Obj13894 *)d)->f1050=1;} ((struct Obj03256 *)p)->f834=GAME_DATA_GetPlayerStatus(*(int *)&((struct Obj04478 *)c)->f14,1-GFL_NET_SYSTEM_GetCurrentAid());POKETRADE_PROC_InitTradeWork(a,b,c,p,1);}
