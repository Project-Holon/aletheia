/*
 * function: ZUKAN_DETAIL_AREA_LoadMarkerResources
 * address:  0x021C0B10
 * packet:   pkt_ov208_021C0B10
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   POKE_TOOL_GetIconCellArcIdSub  0x0201BC78  thumb
 *   POKE_TOOL_GetIconCellEntryIdSub  0x0201BCEC  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj14654.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void *func_020490F4(u32 id, u32 heap);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int POKE_TOOL_GetIconCellArcIdSub(void);
extern int POKE_TOOL_GetIconCellEntryIdSub(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);

void ZUKAN_DETAIL_AREA_LoadMarkerResources(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(7, *heap);
    ((struct Obj14654 *)p)->f54 = CLACT_RegisterPaletteCompressed(h, POKE_TOOL_GetIconPaletteArcId(), 1, 0, *heap);
    ((struct Obj14654 *)p)->f58 = CLACT_RegisterCellAnim(h, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryIdSub(), *heap);
    ARC_TOOL_DeleteHandle(h);
}
