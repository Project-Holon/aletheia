/*
 * function: RESEARCH_GRAPH_RegisterCursorResources
 * address: 0x021C02C8
 * packet: pkt_ov217_021C02C8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 00 00 at 021C0356 is two-byte alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj06713.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void RESEARCH_GRAPH_RegisterCursorResources(char *p)
{
    u16 heap = ((struct Obj06713 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = CLACT_RegisterCharacter((void *)((u32)h), 15, 0, 0, heap);
    int b = CLACT_RegisterPaletteEx((void *)((u32)h), 16, 0, 192, 0, 3, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 14, 17, heap);
    int d;
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(83, heap);
    d = CLACT_RegisterPaletteEx((void *)((u32)h), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj06713 *)p)->f368 = a;
    ((struct Obj06713 *)p)->f36C = b;
    ((struct Obj06713 *)p)->f374 = d;
    ((struct Obj06713 *)p)->f370 = c;
}
