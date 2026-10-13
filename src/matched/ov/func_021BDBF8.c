/*
 * function: EVENT_ENTRANCE_OUT_PostBgmFadeIn
 * address:  0x021BDBF8
 * packet:   pkt_021BDBF8
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
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_PostFadeIn  0x02029D7C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02661.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern u32 FIELD_SOUND_SYSTEM_PostFadeIn(u32, u32);

int EVENT_ENTRANCE_OUT_PostBgmFadeIn(u32 a)
{
return FIELD_SOUND_SYSTEM_PostFadeIn(GAME_DATA_GetBgmInfo((const struct BigObj *)*(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8)), *(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8));
}

