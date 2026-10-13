/*
 * function: FIELD_PLAYER_GRID_IsHopping
 * address:  0x021A54A0
 * packet:   pkt_021A54A0
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
 *   FIELD_PLAYER_GRID_IsHopFlagSet  0x021A53BC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_PLAYER_GRID_IsHopFlagSet(u32 a);

int FIELD_PLAYER_GRID_IsHopping(u32 a)
{
if (FIELD_PLAYER_GRID_IsHopFlagSet(a) == 1) {
    return 1;
}
return 0;
}

