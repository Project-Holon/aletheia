/*
 * function: FIELD_PLAYER_GRID_GetHopFallResult
 * address:  0x021A48A4
 * packet:   pkt_021A48A4
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
 *   FIELD_PLAYER_GRID_IsAtGroundHeight  0x021A56C0  thumb  ov021
 *   FIELD_PLAYER_GRID_FinishHop  0x021A54B4  thumb  ov021
 *   FIELD_PLAYER_GRID_SetHopFlag  0x021A53A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FIELD_PLAYER_GRID_SetHopFlag(u32 *p, int on);
extern void FIELD_PLAYER_GRID_FinishHop(u8 *p);
extern u32 FIELD_PLAYER_GRID_IsAtGroundHeight(u32 *p, u32 a1, u32 a2, u32 a3);

int FIELD_PLAYER_GRID_GetHopFallResult(u32 a, u32 b, u32 c, u32 d)
{
if (FIELD_PLAYER_GRID_IsAtGroundHeight((u32 *)a, b, c, d) == 1) {
    FIELD_PLAYER_GRID_FinishHop((u8 *)a);
    FIELD_PLAYER_GRID_SetHopFlag((u32 *)a, 0);
    return 1;
}
return 9;
}

