/*
 * function: FIELD_G3D_MAP_ReadWhole
 * address: 0x02169A88
 * packet: pkt_ov010_02169A88
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 */
#include "../include/Obj00281.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ArcFile;
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *,u32);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *,u32,void *);
void FIELD_G3D_MAP_ReadWhole(u8 *p,u32 n) { void *out; u32 v; out=((struct Obj00281 *)p)->fD4; v=ARC_TOOL_GetHandleMemberSize(*(struct ArcFile * *)&((struct Obj00281 *)p)->f10,n); ARC_TOOL_ReadHandleMember(*(struct ArcFile * *)&((struct Obj00281 *)p)->f10,n,out); ((struct Obj00281 *)p)->fBC=v; ((struct Obj00281 *)p)->fB4=v; ((struct Obj00281 *)p)->fB8=v; }
