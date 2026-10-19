/*
 * function: POKETRADE_PROC_SetupGameData
 * address: 0x021DC538
 * packet: pkt_ov119_021DC538
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GAME_DATA_GetMyStatusPlayer 0x02012950 thumb
 *   gGameDataAllocTag 0x021E80B0 data a4
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;extern unsigned POKE_TOOL_GetPartyParamSize(void);extern void *func_02030734(unsigned,unsigned,int,const char *,u16);extern char gGameDataAllocTag[];extern int GAME_DATA_GetBoxManager(void *);extern int GAME_DATA_GetMyStatus(void *);extern void *GAME_DATA_GetMyParty(void *p);extern int POKETRADE_PROC_IsNetSession(void *);extern int GFL_NET_SYSTEM_GetCurrentAid(void);extern int GAME_DATA_GetMyStatusPlayer(void *,int);
void POKETRADE_PROC_SetupGameData(char *p,void *q) {unsigned i;for(i=0;i<3;i++)*(int *)(p+0x1064+i*4)=(int)func_02030734(0x91,POKE_TOOL_GetPartyParamSize(),1,gGameDataAllocTag,0xfde);if(q){((struct Obj00001 *)p)->f82C=q;*(int *)&((struct Obj00001 *)p)->f828=GAME_DATA_GetBoxManager(q);*(int *)&((struct Obj00001 *)p)->f830=GAME_DATA_GetMyStatus(q);((struct Obj00001 *)p)->f838=GAME_DATA_GetMyParty(q);if(*(int *)&((struct Obj00001 *)p)->f834==0){if(POKETRADE_PROC_IsNetSession(p)){*(int *)&((struct Obj00001 *)p)->f834=GAME_DATA_GetMyStatusPlayer(q,1-GFL_NET_SYSTEM_GetCurrentAid());return;}*(int *)&((struct Obj00001 *)p)->f834=GAME_DATA_GetMyStatusPlayer(q,1);}}}
