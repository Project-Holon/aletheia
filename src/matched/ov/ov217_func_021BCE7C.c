/*
 * function: func_021BCE7C
 * address: 0x021BCE7C
 * packet: pkt_ov217_021BCE7C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 * Original narrows heap at 020490F4; its extern takes u16.
 */
#include "../include/Obj00025.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021BCE7C(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c, d;
    heap = ((struct Obj00025 *)p)->f8;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = CLACT_RegisterCharacter((void *)((u32)arc), 15, 0, 0, heap);
    b = CLACT_RegisterPaletteEx((void *)((u32)arc), 16, 0, 192, 0, 4, heap);
    c = CLACT_RegisterCellAnim((void *)((u32)arc), 14, 17, heap);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(83, (u16)heap);
    d = CLACT_RegisterPaletteEx((void *)((u32)arc), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(arc);
    ((struct Obj00025 *)p)->fF8 = a;
    ((struct Obj00025 *)p)->fFC = b;
    ((struct Obj00025 *)p)->f100 = c;
    ((struct Obj00025 *)p)->f104 = d;
}
