/*
 * function: FIELD_PLAYER_FinishGridMove
 * address:  0x021A3644
 * packet:   pkt_ov021_021A3644
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   FIELD_PLAYER_GRID_IsHopping  0x021A54A0  thumb
 *   FIELD_PLAYER_GRID_FinishHop  0x021A54B4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_PLAYER_GRID_IsHopping(u32 a);
extern void FIELD_PLAYER_GRID_FinishHop(u8 *p);

void FIELD_PLAYER_FinishGridMove(void **p)
{
    if (FIELDMAP_GetMoveKind(p[0]) == 0 && FIELD_PLAYER_GRID_IsHopping((u32)p[2]) == 1)
        FIELD_PLAYER_GRID_FinishHop(p[2]);
}
