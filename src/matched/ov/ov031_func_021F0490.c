/*
 * function: UNION_SUBDISP_LoadActorRes
 * address:  0x021F0490
 * packet:   pkt_ov031_021F0490
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 */
#include "../include/Obj09791.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

void UNION_SUBDISP_LoadActorRes(char *p, u32 heap)
{
    ((struct Obj09791 *)p)->fC = CLACT_RegisterPaletteEx((void *)heap, 0x13, 1, 0, 0, 3, 0x15);
    ((struct Obj09791 *)p)->f8 = CLACT_RegisterCharacter((void *)heap, 0xE, 0, 1, 0x15);
    ((struct Obj09791 *)p)->f10 = CLACT_RegisterCellAnim((void *)heap, 0xC, 0xD, 0x15);
}
