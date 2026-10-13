/*
 * function: FIELD_PLAYER_GRID_IsHopStartTileKind
 * address:  0x021A55FC
 * packet:   pkt_021A55FC
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
 *   MAP_ATTR_IsDeepSand  0x021AB404  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int MAP_ATTR_IsDeepSand(int x);

int FIELD_PLAYER_GRID_IsHopStartTileKind(int a)
{
if (MAP_ATTR_IsDeepSand(a) == 1) {
    return 1;
}
return 0;
}

