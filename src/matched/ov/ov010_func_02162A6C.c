/*
 * function: EVENTDATA_SYSTEM_GetPosEventCenterPosThunk
 * address:  0x02162A6C
 * packet:   pkt_ov010_02162A6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * EVENTDATA_SYSTEM_GetPosEventCenterPos.  Blocker of ov021 SCRCMD_WarpToPositionEvent.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetPosEventCenterPos  0x02162ECC  thumb  ov010
 */

extern void EVENTDATA_SYSTEM_GetPosEventCenterPos(const char *p, int *out);

void EVENTDATA_SYSTEM_GetPosEventCenterPosThunk(int a, int b)
{
    EVENTDATA_SYSTEM_GetPosEventCenterPos((const char *)a, (int *)b);
}
