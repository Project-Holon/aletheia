/*
 * function: FIELD_GROUND_ANIME_GetEntryPosByMapKind
 * address:  0x021A811C
 * packet:   pkt_021A811C
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
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_GROUND_ANIME_GetRailEntryPos  0x021A8198  thumb  ov021
 *   FIELD_GROUND_ANIME_GetGridEntryPos  0x021A8140  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern u32 FIELD_GROUND_ANIME_GetGridEntryPos(u32, u32);
extern u32 FIELD_GROUND_ANIME_GetRailEntryPos(u32, u32);

int FIELD_GROUND_ANIME_GetEntryPosByMapKind(u32 a, u32 b)
{
if (FIELDMAP_GetMoveKind((u8 *)a) == 1) {
    return FIELD_GROUND_ANIME_GetRailEntryPos(a, b);
}
return FIELD_GROUND_ANIME_GetGridEntryPos(a, b);
}

