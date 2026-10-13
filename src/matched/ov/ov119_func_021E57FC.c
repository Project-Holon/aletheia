/*
 * function: func_021E57FC
 * address: 0x021E57FC
 * packet: pkt_ov119_021E57FC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj03782.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021E57FC(int p)
{
    void *a;
    if (((struct Obj03782 *)p)->f898 == 0) {
        a = func_020490F4(0x66, ((struct Obj03782 *)p)->f5F4);
        ((struct Obj03782 *)p)->f898 = CLACT_RegisterCharacter(a, 0x15, 0, 0, ((struct Obj03782 *)p)->f5F4);
        ((struct Obj03782 *)p)->f884 = CLACT_RegisterPaletteEx(a, 0x12, 0, 0xc0, 0, 6, ((struct Obj03782 *)p)->f5F4);
        ((struct Obj03782 *)p)->f8B4 = CLACT_RegisterCellAnim(a, 0x14, 0x13, ((struct Obj03782 *)p)->f5F4);
        ARC_TOOL_DeleteHandle(a);
    }
}
