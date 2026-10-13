/*
 * function: FIELD_EVENT_CHECK_StartConnectEvent
 * address:  0x0218AD80
 * packet:   pkt_ov021_0218AD80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up entry id through EVENTDATA_SYSTEM_GetConnectData, optionally resolves its argument,
 * then dispatches to ov020 EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate for kind 6 or EVENT_MAPCHANGE_CreateExitWarpEvent
 * otherwise.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectGridExitOffset  0x021626A8  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate  0x02185410  thumb  ov020
 *   EVENT_MAPCHANGE_CreateExitWarpEvent  0x02185360  thumb  ov020
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00705.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern u16 EVENTDATA_SYSTEM_GetConnectGridExitOffset(void *b, void *pos);
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);
extern void *EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate(void *p, int u, int a, int b);
extern void *EVENT_MAPCHANGE_CreateExitWarpEvent(void *p, int u, int a, int b);

void FIELD_EVENT_CHECK_StartConnectEvent(u8 *p, void *a, int id, void *arg)
{
    void *obj = EVENTDATA_SYSTEM_GetConnectData(((struct Obj00705 *)p)->fC, (u16)id);
    void *d;

    if (arg != 0)
        d = (void *)EVENTDATA_SYSTEM_GetConnectGridExitOffset(obj, arg);
    else
        d = 0;
    if (EVENTDATA_SYSTEM_GetConnectExitType(obj) == 6)
        EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate(((struct Obj00705 *)p)->f4, (int)a, (int)obj, (int)d);
    else
        EVENT_MAPCHANGE_CreateExitWarpEvent(((struct Obj00705 *)p)->f4, (int)a, (int)obj, (int)d);
}
