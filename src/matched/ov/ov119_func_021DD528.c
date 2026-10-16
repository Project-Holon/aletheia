/*
 * function: POKETRADE_NEGO_RegisterIconResources
 * address: 0x021DD528
 * packet: pkt_ov119_021DD528
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   POKE_TOOL_GetIconCellArcIdSub 0x0201BC78 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj06425.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int POKE_TOOL_GetIconCellArcIdSub(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
extern void ARC_TOOL_DeleteHandle(void *);
void POKETRADE_NEGO_RegisterIconResources(char *p,int n)
{
    void *v;int off;int a;v=func_020490F4(7,((struct Obj06425 *)p)->f5F4);off=96;if(n!=1)off=0;((struct Obj06425 *)p)->f890=CLACT_RegisterPaletteCompressed(v,POKE_TOOL_GetIconPaletteArcId(),n,(u16)off,((struct Obj06425 *)p)->f5F4);a=POKE_TOOL_GetIconCellArcIdSub();((struct Obj06425 *)p)->f8C0=CLACT_RegisterCellAnim(v,a,POKE_TOOL_GetIconCellEntryId(),((struct Obj06425 *)p)->f5F4);ARC_TOOL_DeleteHandle(v);
}
