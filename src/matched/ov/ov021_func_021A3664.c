/*
 * function: FIELD_PLAYER_CreateNogrid
 * address:  0x021A3664
 * packet:   pkt_ov021_021A3664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_Create  0x021A5880  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u8 *FIELD_PLAYER_NOGRID_Create(u8 *obj, int heap);

void FIELD_PLAYER_CreateNogrid(u32 *p, u32 heap)
{
    p[3] = (u32)FIELD_PLAYER_NOGRID_Create((u8 *)p[1], heap);
}
