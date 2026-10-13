/*
 * function: func_021DC538
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
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GAME_DATA_GetPlayerStatus 0x02012950 thumb
 *   d_021E80B0 0x021E80B0 data a4
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;extern unsigned POKE_TOOL_GetPartyParamSize(void);extern void *func_02030734(unsigned,unsigned,int,const char *,u16);extern char d_021E80B0[];extern int GAME_DATA_GetBoxManager(void *);extern int GAME_DATA_GetMyStatus(void *);extern void *GAME_DATA_GetMyParty(void *p);extern int func_021D8A24(void *);extern int GFL_NET_SYSTEM_GetCurrentAid(void);extern int GAME_DATA_GetPlayerStatus(void *,int);
void func_021DC538(char *p,void *q) {unsigned i;for(i=0;i<3;i++)*(int *)(p+0x1064+i*4)=(int)func_02030734(0x91,POKE_TOOL_GetPartyParamSize(),1,d_021E80B0,0xfde);if(q){((struct Obj00001 *)p)->f82C=q;*(int *)&((struct Obj00001 *)p)->f828=GAME_DATA_GetBoxManager(q);*(int *)&((struct Obj00001 *)p)->f830=GAME_DATA_GetMyStatus(q);((struct Obj00001 *)p)->f838=GAME_DATA_GetMyParty(q);if(*(int *)&((struct Obj00001 *)p)->f834==0){if(func_021D8A24(p)){*(int *)&((struct Obj00001 *)p)->f834=GAME_DATA_GetPlayerStatus(q,1-GFL_NET_SYSTEM_GetCurrentAid());return;}*(int *)&((struct Obj00001 *)p)->f834=GAME_DATA_GetPlayerStatus(q,1);}}}
