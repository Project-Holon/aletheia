/*
 * function: EVENT_ENTRANCE_IN_GetPlayerForm
 * address:  0x021BD93C
 * packet:   pkt_021BD93C
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
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18244.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);

void EVENT_ENTRANCE_IN_GetPlayerForm(u32 a, u32 b, u32 c, u32 d)
{
FIELD_PLAYER_GetFormCode(FIELDMAP_GetFieldPlayer((struct Obj00020 *)(*(u32 *)((u8 *)(((struct Obj18244 *)((u8 *)(a)))->f8) + 12))));
}

