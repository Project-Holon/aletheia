/*
 * function: GURU2_MAIN_StateRoundEndChild
 * address: 0x021DF204
 * packet: pkt_ov137_021DF204
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_BroadcastResult 0x021E19C0 thumb ov137
 *   GURU2_MAIN_FindNearestPlayerRecord 0x021E0A44 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj04542.h"
#include "../include/Obj23757.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_MAIN_BroadcastResult(char *,int);
extern u8 *GURU2_MAIN_FindNearestPlayerRecord(void *);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int GURU2_MAIN_StateRoundEndChild(char *p) { GURU2_MAIN_BroadcastResult(p,0x4000); *(u8 * *)&((struct Obj04542 *)p)->f28=GURU2_MAIN_FindNearestPlayerRecord(p); if(((struct Obj23757 *)(*(u8 * *)&((struct Obj04542 *)p)->f28))->fC!=GFL_NET_SYSTEM_GetCurrentAid()) ((struct Obj04542 *)p)->f0=30; return 0; }
