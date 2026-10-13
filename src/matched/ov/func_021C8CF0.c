/*
 * function: FIELD_TILE_MOVE_IsSlideTile
 * address:  0x021C8CF0
 * packet:   pkt_021C8CF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_TILE_MOVE_HasSlideEntry with no argument change.
 *
 * symbols:
 *   FIELD_TILE_MOVE_HasSlideEntry  0x021C8BC4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_TILE_MOVE_HasSlideEntry(u32 a);

int FIELD_TILE_MOVE_IsSlideTile(u32 a)
{
    return FIELD_TILE_MOVE_HasSlideEntry(a);
}
