/*
 * function: SCRCMD_PLAYER_GRID_EVENT_WaitA
 * address:  0x021C457C
 * packet:   pkt_ov021_021C457C
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
 *   FIELD_PLAYER_GRID_EVENT_IsHopDone  0x021C1094  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_DeleteHopTask  0x021C10A0  thumb  ov021
 *   SCRCMD_WORK_GetTargetObject  0x0215A64C  thumb  ov010
 */

extern void *SCRCMD_WORK_GetTargetObject(void *a);
extern int FIELD_PLAYER_GRID_EVENT_IsHopDone(void *x);
typedef unsigned int   u32;
extern int FIELD_PLAYER_GRID_EVENT_DeleteHopTask(u32 a);

int SCRCMD_PLAYER_GRID_EVENT_WaitA(void *a, void *b)
{
    void *x = SCRCMD_WORK_GetTargetObject(b);

    if (FIELD_PLAYER_GRID_EVENT_IsHopDone(x) == 1) {
        FIELD_PLAYER_GRID_EVENT_DeleteHopTask((u32)x);
        return 1;
    }
    return 0;
}
