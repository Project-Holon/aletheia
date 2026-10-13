/*
 * function: FIELD_PLAYER_CreateGrid
 * address:  0x021A35E0
 * packet:   pkt_ov021_021A35E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GRID_Create  0x021A4140  thumb  ov021
 */

typedef unsigned int u32;

u32 *FIELD_PLAYER_GRID_Create(u32 a, u32 b);

void FIELD_PLAYER_CreateGrid(u32 *p, u32 heap)
{
    p[2] = (u32)FIELD_PLAYER_GRID_Create(p[1], heap);
}
