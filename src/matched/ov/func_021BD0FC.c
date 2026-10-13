/*
 * function: FIELD_PLACE_NAME_SaveZoneToSave
 * address:  0x021BD0FC
 * packet:   pkt_021BD0FC
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
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_020089A0  0x020089A0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00575.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Big;
struct Ctx;
struct Sub02008828Obj;
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u32 func_020089A0(u32, u32);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);

int FIELD_PLACE_NAME_SaveZoneToSave(u32 a)
{
return func_020089A0((u32)func_02008854(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj00575 *)((u8 *)(a)))->f0)))), *(u16 *)((u8 *)((a + 70))));
}

