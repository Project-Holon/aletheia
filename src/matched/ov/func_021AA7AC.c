/*
 * function: EFFECT_ENCOUNT_Init
 * address:  0x021AA7AC
 * packet:   pkt_021AA7AC
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
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   EFFECT_ENCOUNT_LoadSetting  0x021AA7DC  thumb  ov021
 *   EFFECT_ENCOUNT_RestoreSpot  0x021AAB74  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07219.h"
#include "../include/Obj09585.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 EFFECT_ENCOUNT_LoadSetting(u32, u32);
extern u32 EFFECT_ENCOUNT_RestoreSpot(u32, u32);

int EFFECT_ENCOUNT_Init(u32 a, u32 b)
{
((struct Obj09585 *)((u8 *)(b)))->f0 = FIELDMAP_GetEffect((u8 *)(*(u32 *)&((struct Obj07219 *)((u8 *)(a)))->f0));
EFFECT_ENCOUNT_LoadSetting(a, b);
return EFFECT_ENCOUNT_RestoreSpot(a, b);
}

