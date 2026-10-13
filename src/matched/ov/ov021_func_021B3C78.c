/*
 * function: SCRCMD_PROC_FLD_LoadCursorResources
 * address:  0x021B3C78
 * packet:   pkt_ov021_021B3C78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_PROC_FLD_LoadCursorResources 0x021B3C78 thumb
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj02389.h"

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);

void SCRCMD_PROC_FLD_LoadCursorResources(char *p)
{
    void *q = func_020490F4(54, ((struct Obj02389 *)p)->f4);

    ((struct Obj02389 *)p)->f1D4 = (void *)CLACT_RegisterPaletteEx(q, 10, 0, 0, 0, 1, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1D8 = (void *)CLACT_RegisterCharacter(q, 7, 0, 0, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1E4 = (void *)CLACT_RegisterCharacter(q, 4, 0, 0, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1DC = (void *)CLACT_RegisterCellAnim(q, 8, 9, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1E8 = (void *)CLACT_RegisterCellAnim(q, 5, 6, ((struct Obj02389 *)p)->f4);
    ARC_TOOL_DeleteHandle(q);
}
