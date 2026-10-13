/*
 * function: FIELD_TILE_MOVE_SpinSelectEntry
 * address:  0x021C8B48
 * packet:   pkt_ov021_021C8B48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_TILE_MOVE_FindSpinEntry  0x021C8984  thumb  ov021
 *   FIELD_TILE_MOVE_GetSpinTileAttr  0x021C8AAC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
extern u16 FIELD_TILE_MOVE_GetSpinTileAttr(P *p);
extern void *FIELD_TILE_MOVE_FindSpinEntry(u16 id);
void FIELD_TILE_MOVE_SpinSelectEntry(P *p)
{
    void *e = FIELD_TILE_MOVE_FindSpinEntry(FIELD_TILE_MOVE_GetSpinTileAttr(p));
    if (e != 0)
        p->f10 = e;
}
