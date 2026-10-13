/*
 * function: FIELD_PLAYER_CORE_ApplyFormCodeModel
 * address:  0x021A3998
 * packet:   pkt_021A3998
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
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_SetFormCodeModel  0x021A3B3C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern u32 FIELD_PLAYER_CORE_SetFormCodeModel(u32, u32);

int FIELD_PLAYER_CORE_ApplyFormCodeModel(u8 *a)
{
    u32 b;
    u32 c;
    u32 d;
return FIELD_PLAYER_CORE_SetFormCodeModel((u32)a, FIELD_PLAYER_CORE_GetFormCode(a));
}

