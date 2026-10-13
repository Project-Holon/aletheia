/*
 * function: FIELD_TILE_MOVE_IsSpinTile
 * address:  0x021C8A74
 * packet:   pkt_021C8A74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_TILE_MOVE_HasSpinEntry with no argument change.
 *
 * symbols:
 *   FIELD_TILE_MOVE_HasSpinEntry  0x021C89A8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_TILE_MOVE_HasSpinEntry(u32 a);

int FIELD_TILE_MOVE_IsSpinTile(u32 a)
{
    return FIELD_TILE_MOVE_HasSpinEntry(a);
}
