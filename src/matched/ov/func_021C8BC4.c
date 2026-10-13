/*
 * function: FIELD_TILE_MOVE_HasSlideEntry
 * address:  0x021C8BC4
 * packet:   pkt_021C8BC4
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
 *   FIELD_TILE_MOVE_FindSlideEntry  0x021C8B9C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_TILE_MOVE_FindSlideEntry(u32);

int FIELD_TILE_MOVE_HasSlideEntry(u32 a)
{
if (FIELD_TILE_MOVE_FindSlideEntry(a) != 0) {
    return 1;
}
return 0;
}

