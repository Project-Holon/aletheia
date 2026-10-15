/*
 * function: FIELD_GROUND_ANIME_GetPlayerMoveMode
 * address:  0x021A80FC
 * packet:   pkt_021A80FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);

int FIELD_GROUND_ANIME_GetPlayerMoveMode(u32 a)
{
return (((u32)FIELD_PLAYER_GetDirDisp(FIELDMAP_GetFieldPlayer((struct Obj00020 *)a)) << 24) >> 24);
}

