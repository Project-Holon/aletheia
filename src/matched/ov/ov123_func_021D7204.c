/*
 * function: GSYNC_STATE_ResetSlotActors
 * address: 0x021D7204
 * packet: pkt_ov123_021D7204
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GSYNC_DISP_SetSlotAnimSeq 0x021D62BC thumb ov123
 *   GSYNC_DISP_CreateSlotActor 0x021D62B4 thumb ov123
 *   GSYNC_DISP_SetMainActorAnimSeq 0x021D63D4 thumb ov123
 */
#include "../include/Obj10444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GSYNC_DISP_SetSlotAnimSeq(u8 *,int,u32);
extern void GSYNC_DISP_CreateSlotActor(u8 *p, unsigned int i);
extern void GSYNC_DISP_SetMainActorAnimSeq(u8 *);
void GSYNC_STATE_ResetSlotActors(u8 *p) { GSYNC_DISP_SetSlotAnimSeq(*(u8 * *)&((struct Obj10444 *)p)->f14,0,0); GSYNC_DISP_CreateSlotActor((u8 *)(*(char * *)&((struct Obj10444 *)p)->f14),12); GSYNC_DISP_SetMainActorAnimSeq(*(u8 * *)&((struct Obj10444 *)p)->f14); }
