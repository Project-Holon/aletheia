/*
 * function: FIELD_TILE_MOVE_FindSpinEntry
 * address:  0x021C8984
 * packet:   pkt_ov021_021C8984
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFieldTileMoveSpinTable  0x021DAB24  data  ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { u16 id; u16 pad; u32 v; } E;
extern E sFieldTileMoveSpinTable[4];
E *FIELD_TILE_MOVE_FindSpinEntry(u16 id)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (id == sFieldTileMoveSpinTable[i].id)
            return &sFieldTileMoveSpinTable[i];
    }
    return 0;
}
