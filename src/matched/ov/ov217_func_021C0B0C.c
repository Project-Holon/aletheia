/*
 * function: func_021C0B0C
 * address: 0x021C0B0C
 * packet: pkt_ov217_021C0B0C
 * region: ov217
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
#include "../include/Obj00791.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021C0B0C(u8 *p)
{
    u16 heap = ((struct Obj00791 *)p)->f0;
    void *h = func_020490F4(83, (u16)((heap & 0x7FFF) | 0x8000));
    int a = CLACT_RegisterCharacter((void *)((u32)h), 20, 0, 0, heap);
    int b = CLACT_RegisterPaletteEx((void *)((u32)h), 19, 0, 0, 0, 4, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 21, 24, heap);
    ((struct Obj00791 *)p)->f14 = a;
    ((struct Obj00791 *)p)->f18 = b;
    ((struct Obj00791 *)p)->f1C = c;
    ARC_TOOL_DeleteHandle(h);
}
