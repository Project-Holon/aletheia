/*
 * function: GSYNC_DISP_LoadEffectResources
 * address: 0x021D6404
 * packet: pkt_ov123_021D6404
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 */
#include "../include/Obj00343.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
typedef signed int     s32;
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void ARC_TOOL_DeleteHandle(void *);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
void GSYNC_DISP_LoadEffectResources(u8 *p)
{
    void *h;
    h = func_020490F4(7, ((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f28 = (void *)CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 2, 0, ((struct Obj00343 *)p)->f43C4);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(143, ((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f5C = (void *)CLACT_RegisterCellAnim(h, 14, 27, ((struct Obj00343 *)p)->f43C4);
    ARC_TOOL_DeleteHandle(h);
}
