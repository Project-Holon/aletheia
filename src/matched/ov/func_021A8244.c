/*
 * function: FIELD_GROUND_ANIME_IsBuildModelDone
 * address:  0x021A8244
 * packet:   pkt_021A8244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_GROUND_ANIME_HasBuildModel  0x021A8268  thumb  ov021
 *   FIELD_BUILDMODEL_TryOpenNodeCurrentSlot  0x0218C8D8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18069.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(void *p);
extern int FIELD_GROUND_ANIME_HasBuildModel(u32 a);

int FIELD_GROUND_ANIME_IsBuildModelDone(u32 a)
{
if (FIELD_GROUND_ANIME_HasBuildModel(a) == 0) {
    return 1;
}
if (FIELD_BUILDMODEL_TryOpenNodeCurrentSlot((void *)(((struct Obj18069 *)((u8 *)(a)))->f28)) != 0) {
    return 1;
}
return 0;
}

