/*
 * function: SCRCMD_POKE_ICON_DeleteIcon
 * address:  0x021D26AC
 * packet:   pkt_021D26AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04899.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

int SCRCMD_POKE_ICON_DeleteIcon(u32 *a)
{
CLACT_DeleteActor((struct Obj *)(((struct Obj04899 *)((u8 *)(a)))->f8));
CLACT_ReleaseCharacter(((struct Obj04899 *)((u8 *)(a)))->fC);
CLACT_ReleasePalette(((struct Obj04899 *)((u8 *)(a)))->f10);
CLACT_ReleaseCellAnim(((struct Obj04899 *)((u8 *)(a)))->f14);
return CLACT_DeleteUnit((struct Bank *)(((struct Obj04899 *)((u8 *)(a)))->f4));
}

