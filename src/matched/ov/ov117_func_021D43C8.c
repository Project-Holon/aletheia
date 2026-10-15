/*
 * function: POKETRADE_DEMO_COMMON_LoadUnitResources
 * address:  0x021D43C8
 * packet:   pkt_ov117_021D43C8
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 */
#include "../include/Obj03768.h"
#include "../include/Obj22639.h"

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);

void POKETRADE_DEMO_COMMON_LoadUnitResources(void *p)
{
    void *h = func_020490F4(0x67, ((struct Obj03768 *)p)->f5F4);
    ((struct Obj03768 *)p)->f8A8 = CLACT_RegisterCharacter(h, 2, 0, 0, ((struct Obj03768 *)p)->f5F4);
    ((struct Obj03768 *)p)->f88C = CLACT_RegisterPaletteEx(h, 3, 0, 0xE0, 0, 1, ((struct Obj03768 *)p)->f5F4);
    ((struct Obj03768 *)p)->f8BC = CLACT_RegisterCellAnim(h, 1, 0, ((struct Obj03768 *)p)->f5F4);
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj22639 *)((char *)((struct Obj03768 *)p)->fC))->fB0 = 0;
}
