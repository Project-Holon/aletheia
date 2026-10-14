/*
 * function: HALL_OF_FAME_LoadUiResources
 * address: 0x021B7C78
 * packet: pkt_ov180_021B7C78
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00547.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void ARC_TOOL_DeleteHandle(void *);
void HALL_OF_FAME_LoadUiResources(char *p)
{
    void *h = func_020490F4(0xD8, 0x808D);
    ((struct Obj00547 *)p)->f90D4 = (void *)CLACT_RegisterCharacter(h, 0x18, 0, 0, 0x8D);
    ((struct Obj00547 *)p)->f90EC = (void *)CLACT_RegisterPalette(h, 3, 0, 0, 0x8D);
    ((struct Obj00547 *)p)->f9108 = (void *)CLACT_RegisterCellAnim(h, 0x1A, 0x20, 0x8D);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(0x17, 0x808D);
    ((struct Obj00547 *)p)->f90F0 = (void *)CLACT_RegisterPaletteCompressed(h, 5, 0, 0xA0, 0x8D);
    ARC_TOOL_DeleteHandle(h);
}
