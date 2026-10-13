/*
 * function: SCRCMD_PLAYER_GRID_EVENT_WaitB
 * address:  0x021C4608
 * packet:   pkt_ov021_021C4608
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   FIELD_PLAYER_GRID_EVENT_IsJumpDone  0x021C12C4  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_DeleteJumpTask  0x021C12D0  thumb  ov021
 *   SCRCMD_WORK_GetTargetObject  0x0215A64C  thumb  ov010
 */

extern void *SCRCMD_WORK_GetTargetObject(void *a);
extern int FIELD_PLAYER_GRID_EVENT_IsJumpDone(void *x);
extern void FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(void *x);

int SCRCMD_PLAYER_GRID_EVENT_WaitB(void *a, void *b)
{
    void *x = SCRCMD_WORK_GetTargetObject(b);

    if (FIELD_PLAYER_GRID_EVENT_IsJumpDone(x) == 1) {
        FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(x);
        return 1;
    }
    return 0;
}
