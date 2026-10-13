/*
 * function: func_021BCDF0
 * address: 0x021BCDF0
 * packet: pkt_ov217_021BCDF0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 * 0204ABF0 is void in its source but forwards to the int-returning
 * 0204AC18; the original stores its live r0 result. 020490F4 narrows heap.
 */
#include "../include/Obj00025.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021BCDF0(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c;
    heap = ((struct Obj00025 *)p)->f8;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = CLACT_RegisterCharacter((void *)((u32)arc), 15, 0, 1, heap);
    b = CLACT_RegisterPalette((void *)arc, 16, 1, 0, heap);
    c = CLACT_RegisterCellAnim((void *)((u32)arc), 14, 17, heap);
    ((struct Obj00025 *)p)->f108 = a;
    ((struct Obj00025 *)p)->f10C = b;
    ((struct Obj00025 *)p)->f110 = c;
    ARC_TOOL_DeleteHandle(arc);
}
