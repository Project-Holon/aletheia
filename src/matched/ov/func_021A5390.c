/*
 * function: FIELD_PLAYER_GRID_IsHoldFlagSet
 * address:  0x021A5390
 * packet:   pkt_021A5390
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
 *   FIELD_PLAYER_GRID_HasFlag  0x021A5318  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_PLAYER_GRID_HasFlag(u32 *p, u32 m);

int FIELD_PLAYER_GRID_IsHoldFlagSet(u32 a)
{
if (FIELD_PLAYER_GRID_HasFlag((u32 *)a, 8) != 0) {
    return 1;
}
return 0;
}

