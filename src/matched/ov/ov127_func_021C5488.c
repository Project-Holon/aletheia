/*
 * unit: yes
 * function: WF2DMAP_OBJCMD_SpawnIdle, WF2DMAP_OBJCMD_StepNoop3
 * address: 0x021C5488
 * packet: pkt_ov127_021C5488
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJDRAW_FillSpawnDesc 0x021C5564 thumb ov127
 */
#include "../include/Obj10474.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WF2DMAP_OBJ_GetSlot(u8 *,unsigned int);
extern void WF2DMAP_OBJDRAW_FillSpawnDesc(u8 *,void *,int,int,int);
int WF2DMAP_OBJCMD_SpawnIdle(u8 *p,int a,int b,const u8 *desc,u8 *out) { int v=WF2DMAP_OBJ_GetSlot(p,5);  if(v==0) { WF2DMAP_OBJDRAW_FillSpawnDesc(out,p,((struct Obj10474 *)desc)->f0,desc[3],desc[2]); return 1; } return 0; }
int WF2DMAP_OBJCMD_StepNoop3(void) { return 0; }
