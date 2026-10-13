/*
 * function: func_021EC254
 * address: 0x021EC254
 * packet: pkt_ov170_021EC254
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj02214.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0201BC3C(void);
typedef signed int     s32;
typedef unsigned int   u32;
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021EC254(char *p)
{
    void *h = func_020490F4(7, 0x4C);
    ((struct Obj02214 *)p)->fA108 = (void *)CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 0, 0x60, 0x4C);
    ((struct Obj02214 *)p)->fA134 = (void *)CLACT_RegisterCellAnim(h, func_0201BC40(), func_0201BCB4(), 0x4C);
    ARC_TOOL_DeleteHandle(h);
}
