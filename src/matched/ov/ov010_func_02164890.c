/*
 * function: CALENDER_LoadZoneTable
 * address: 0x02164890
 * packet: pkt_ov010_02164890
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_TOOL_ReadHandleMemberRange 0x0204944C arm
 */
#include "../include/Obj18979.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
void CALENDER_LoadZoneTable(u8 *p){ARC_TOOL_ReadHandleMemberRange((struct ArcFile *)((struct Obj18979 *)p)->f8,1,2,0x110,p+12);}
