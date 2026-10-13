/*
 * function: func_021C0250
 * address: 0x021C0250
 * packet: pkt_ov217_021C0250
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 00 00 at 021C02A6 is two-byte alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj08438.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021C0250(char *p)
{
    u16 heap = ((struct Obj08438 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = CLACT_RegisterCharacter((void *)((u32)h), 15, 0, 1, heap);
    int b = CLACT_RegisterPalette((void *)h, 16, 1, 0, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 14, 17, heap);
    ((struct Obj08438 *)p)->f378 = a;
    ((struct Obj08438 *)p)->f37C = b;
    ((struct Obj08438 *)p)->f380 = c;
    ARC_TOOL_DeleteHandle(h);
}
