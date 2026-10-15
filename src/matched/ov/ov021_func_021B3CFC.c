/*
 * function: SCRCMD_PROC_FLD_LoadIconResources
 * address:  0x021B3CFC
 * packet:   pkt_ov021_021B3CFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 */
#include "../include/Obj00037.h"

extern unsigned FILE_UTIL_Get(unsigned a, unsigned b);
typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

void SCRCMD_PROC_FLD_LoadIconResources(char *w)
{
    ((struct Obj00037 *)w)->f1EC = (void *)CLACT_RegisterPaletteEx(((struct Obj00037 *)w)->f1F8, FILE_UTIL_Get(1, 2), 0, 0x20, 0, 1, ((struct Obj00037 *)w)->f4);
    ((struct Obj00037 *)w)->f1F0 = (void *)CLACT_RegisterCharacter(((struct Obj00037 *)w)->f1F8, FILE_UTIL_Get(1, 1), 0, 0, ((struct Obj00037 *)w)->f4);
    ((struct Obj00037 *)w)->f1F4 = (void *)CLACT_RegisterCellAnim(((struct Obj00037 *)w)->f1F8, 1, 0, ((struct Obj00037 *)w)->f4);
}
