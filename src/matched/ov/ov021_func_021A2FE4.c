/*
 * function: FIELD_PLAYER_UpdateStepPhase
 * address:  0x021A2FE4
 * packet:   pkt_ov021_021A2FE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   FIELD_PLAYER_GRID_IsOnForcedMoveTile  0x021A548C  thumb
 *   FIELD_PLAYER_GRID_IsHopping  0x021A54A0  thumb
 *   FIELD_PLAYER_NOGRID_IsForcedMove  0x021A59EC  thumb
 *   FIELD_PLAYER_CORE_SetStepPhase  0x021A396C  thumb
 *   FIELD_PLAYER_CORE_UpdateStepPhase  0x021A3818  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_PLAYER_GRID_IsOnForcedMoveTile();
extern int FIELD_PLAYER_GRID_IsHopping(u32 a);
extern u32 FIELD_PLAYER_NOGRID_IsForcedMove(u32 p);
extern void FIELD_PLAYER_CORE_SetStepPhase(u8 *p, u32 v);
extern void FIELD_PLAYER_CORE_UpdateStepPhase(u32 *p);

void FIELD_PLAYER_UpdateStepPhase(u32 *p)
{
    if (FIELDMAP_GetMoveKind((u8 *)p[0]) == 0) {
        if (FIELD_PLAYER_GRID_IsOnForcedMoveTile(p[2]) == 1) {
            FIELD_PLAYER_CORE_SetStepPhase((u8 *)p[1], 2);
            return;
        }
        if (FIELD_PLAYER_GRID_IsHopping(p[2]) == 1) {
            FIELD_PLAYER_CORE_SetStepPhase((u8 *)p[1], 2);
            return;
        }
    } else {
        if (FIELD_PLAYER_NOGRID_IsForcedMove(p[3]) == 1) {
            FIELD_PLAYER_CORE_SetStepPhase((u8 *)p[1], 2);
            return;
        }
    }
    FIELD_PLAYER_CORE_UpdateStepPhase((u32 *)p[1]);
}
