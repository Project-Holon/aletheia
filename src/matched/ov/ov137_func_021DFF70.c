/*
 * function: GURU2_MAIN_LoadActorResources
 * address: 0x021DFF70
 * packet: pkt_ov137_021DFF70
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 */
#include "../include/Obj00835.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
void GURU2_MAIN_LoadActorResources(u8 *p)
{
    void *arc;
    arc = func_020490F4(184,114);
    ((struct Obj00835 *)p)->fD6C = CLACT_RegisterCharacter(arc,6,0,0,114);
    ((struct Obj00835 *)p)->fD70 = CLACT_RegisterPalette(arc,0,0,0,114);
    ((struct Obj00835 *)p)->fD74 = CLACT_RegisterCellAnim(arc,10,14,114);
    ARC_TOOL_DeleteHandle(arc);
    GFL_NET_RefreshWmIconAtTopRight(1,114);
}
