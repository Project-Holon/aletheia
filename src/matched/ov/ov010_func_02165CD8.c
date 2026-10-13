/*
 * function: GAME_BEACON_ACCESSOR_GetFavoriteColorIndex
 * address:  0x02165CD8
 * packet:   pkt_ov010_02165CD8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as the only overlay blocker of ov029 C_GEAR_UpdateBeaconColors.
 *
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetFavoriteColorIndex  0x02165CD8  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct S {
    u8 pad0[12];
    u32 : 12;
    u32 f : 4;
};

u8 GAME_BEACON_ACCESSOR_GetFavoriteColorIndex(struct S *p)
{
    return p->f;
}
