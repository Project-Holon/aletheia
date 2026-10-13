/*
 * function: FIELD_PLAYER_GRID_IsOnForcedMoveTile
 * address:  0x021A548C
 * packet:   pkt_021A548C
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
 *   FIELD_PLAYER_GRID_CheckForcedMoveTile  0x021A5458  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_PLAYER_GRID_CheckForcedMoveTile(u32, u32, u32, u32);

int FIELD_PLAYER_GRID_IsOnForcedMoveTile(u32 a, u32 b, u32 c, u32 d)
{
if (FIELD_PLAYER_GRID_CheckForcedMoveTile(a, 9, c, d) != 0) {
    return 1;
}
return 0;
}

