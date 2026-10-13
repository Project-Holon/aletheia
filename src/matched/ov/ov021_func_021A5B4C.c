/*
 * function: FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck
 * address:  0x021A5B4C
 * packet:   pkt_ov021_021A5B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_RememberKeyDirs  0x021A3AC4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ClearPending  0x021A6738  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ClearForcedMoveEnded  0x021A672C  thumb  ov021
 */

typedef unsigned int u32;

void FIELD_PLAYER_CORE_RememberKeyDirs(u32 a, u32 v);
void FIELD_PLAYER_NOGRID_ClearPending(void *a);
void FIELD_PLAYER_NOGRID_ClearForcedMoveEnded(void *a);

void FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck(u32 *p, u32 a, int mode)
{
    FIELD_PLAYER_CORE_RememberKeyDirs(p[5], a);
    FIELD_PLAYER_NOGRID_ClearPending(p);
    if (mode == 2)
        FIELD_PLAYER_NOGRID_ClearForcedMoveEnded(p);
}
