/*
 * function: FIELD_EVENT_CHECK_StartRailConnectEvent
 * address:  0x0218B2E8
 * packet:   pkt_ov021_0218B2E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectRailExitOffset  0x021626B0  thumb  ov010
 *   EVENT_MAPCHANGE_CreateExitWarpEvent  0x02185360  thumb  ov020
 */
#include "../include/Obj04982.h"

typedef unsigned short u16;

extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern u16 EVENTDATA_SYSTEM_GetConnectRailExitOffset(void *b, void *q);
extern void *EVENT_MAPCHANGE_CreateExitWarpEvent(void *p, int u, int a, int b);

int FIELD_EVENT_CHECK_StartRailConnectEvent(char *p, void *x, int a, int *b)
{
    void *obj = EVENTDATA_SYSTEM_GetConnectData(((struct Obj04982 *)p)->fC, (u16)a);
    return (int)EVENT_MAPCHANGE_CreateExitWarpEvent(((struct Obj04982 *)p)->f4, (int)x, (int)obj, EVENTDATA_SYSTEM_GetConnectRailExitOffset(obj, b));
}
