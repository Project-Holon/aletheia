/*
 * function: FIELD_TILE_MOVE_SlideSelectBumpEntry
 * address:  0x021C8DD4
 * packet:   pkt_ov021_021C8DD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_TILE_MOVE_FindBumpEntry  0x021C8BD8  thumb  ov021
 *   FIELD_TILE_MOVE_GetSlideTileAttr  0x021C8D18  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;
extern u16 FIELD_TILE_MOVE_GetSlideTileAttr(P *p);
extern void *FIELD_TILE_MOVE_FindBumpEntry(u16 id);
void FIELD_TILE_MOVE_SlideSelectBumpEntry(P *p)
{
    p->f14 = FIELD_TILE_MOVE_FindBumpEntry(FIELD_TILE_MOVE_GetSlideTileAttr(p));
}
