/*
 * function: FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady
 * address:  0x021F3868
 * packet:   pkt_021F3868
 * region:   ov061
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetStepKind  0x021A3080  thumb
 *   FIELD_PLAYER_GetStepPhase  0x021A308C  thumb
 */

typedef unsigned int u32;

extern u32 FIELD_PLAYER_GetStepKind(void *x);
extern u32 FIELD_PLAYER_GetStepPhase(void *x);

int FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady(void *unused, void *x)
{
    u32 a = FIELD_PLAYER_GetStepKind(x);

    if (FIELD_PLAYER_GetStepPhase(x) == 3 && a == 0) {
        return 1;
    }
    return 0;
}
