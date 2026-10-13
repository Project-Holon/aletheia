/*
 * function: EVENT_PERAP_RECORD_DeletePokeIcon
 * address:  0x021D201C
 * packet:   pkt_021D201C
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
#include "../include/Obj04135.h"

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

int EVENT_PERAP_RECORD_DeletePokeIcon(u32 a, u32 b, u32 c, u32 d)
{
CLACT_DeleteActor((struct Obj *)(((struct Obj04135 *)((u8 *)(a)))->f3C));
CLACT_ReleaseCharacter(((struct Obj04135 *)((u8 *)(a)))->f40);
CLACT_ReleasePalette(((struct Obj04135 *)((u8 *)(a)))->f44);
CLACT_ReleaseCellAnim(((struct Obj04135 *)((u8 *)(a)))->f48);
return CLACT_DeleteUnit((struct Bank *)(((struct Obj04135 *)((u8 *)(a)))->f38));
}

