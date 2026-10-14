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
 *   func_0201BC3C  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj14654.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);

void ZUKAN_DETAIL_AREA_LoadMarkerResources(u16 *heap, u8 *p, int key)
{
    void *h;

    h = func_020490F4(7, *heap);
    ((struct Obj14654 *)p)->f54 = CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 1, 0, *heap);
    ((struct Obj14654 *)p)->f58 = CLACT_RegisterCellAnim(h, func_0201BC78(), func_0201BCEC(), *heap);
    ARC_TOOL_DeleteHandle(h);
}
