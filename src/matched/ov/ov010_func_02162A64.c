/*
 * function: EVENTDATA_SYSTEM_GetConnectCenterPosThunk
 * address:  0x02162A64
 * packet:   pkt_ov010_02162A64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * EVENTDATA_SYSTEM_GetConnectCenterPos.  Blocker of ov061 func_021F388C.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetConnectCenterPos  0x02162CE8  thumb  ov010
 */

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern void EVENTDATA_SYSTEM_GetConnectCenterPos(const void *p, V3 *out);

void EVENTDATA_SYSTEM_GetConnectCenterPosThunk(const void *p, V3 *out)
{
    EVENTDATA_SYSTEM_GetConnectCenterPos(p, out);
}
