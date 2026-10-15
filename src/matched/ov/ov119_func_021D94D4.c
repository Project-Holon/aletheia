/*
 * function: POKETRADE_PROC_IsSelfMonReady
 * address: 0x021D94D4
 * packet: pkt_ov119_021D94D4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKETRADE_PROC_GetSideValue 0x021D8F20 thumb ov119
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKEPARTY_GetAliveNonEggCount 0x0201AC80 thumb
 */
#include "../include/Obj22724.h"
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *,int);
extern int POKETRADE_PROC_GetSideValue(void *,int);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKEPARTY_GetAliveNonEggCount(void *p);
int POKETRADE_PROC_IsSelfMonReady(char *p) { int w; void *v; int z; if(POKETRADE_PROC_IsHostSide(p)==0) {v=POKETRADE_PROC_GetSideMon(p,0);w=POKETRADE_PROC_GetSideValue(p,0);} else {v=POKETRADE_PROC_GetSideMon(p,1);w=POKETRADE_PROC_GetSideValue(p,1);} z=0;if(POKE_TOOL_GetPartyValue(v,160,0)==0)return z;if(POKE_TOOL_GetPartyValue(v,76,0))return z;if(POKEPARTY_GetAliveNonEggCount((void *)(((struct Obj22724 *)p)->f838))==1 && w!=0)return 1;return 0; }
