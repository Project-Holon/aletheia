/*
 * function: FIELD_TILE_MOVE_FindBumpEntry
 * address:  0x021C8BD8
 * packet:   pkt_ov021_021C8BD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFieldTileMoveBumpTable  0x021DAB44  data  ov021  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
typedef struct { u16 id; u16 a; } E;
extern E sFieldTileMoveBumpTable[4];
E *FIELD_TILE_MOVE_FindBumpEntry(u16 id)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (id == sFieldTileMoveBumpTable[i].id)
            return &sFieldTileMoveBumpTable[i];
    }
    return 0;
}
