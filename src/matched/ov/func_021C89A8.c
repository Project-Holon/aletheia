/*
 * function: FIELD_TILE_MOVE_HasSpinEntry
 * address:  0x021C89A8
 * packet:   pkt_021C89A8
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
 *   FIELD_TILE_MOVE_FindSpinEntry  0x021C8984  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_TILE_MOVE_FindSpinEntry(u32);

int FIELD_TILE_MOVE_HasSpinEntry(u32 a)
{
if (FIELD_TILE_MOVE_FindSpinEntry(a) != 0) {
    return 1;
}
return 0;
}

