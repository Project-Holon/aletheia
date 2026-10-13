/*
 * function: FIELD_EVENT_CHECK_CheckRailConnect
 * address:  0x0218B0CC
 * packet:   pkt_ov021_0218B0CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls the unlabelled ov010 leaf EVENTDATA_SYSTEM_IsConnectDisabled (filed as pkt_ov010_021626EC).
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb
 *   EVENTDATA_SYSTEM_SearchConnectIdByRailLocation  0x02162598  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_IsConnectDisabled  0x021626EC  thumb  ov010
 *   FIELD_EVENT_CHECK_IsConnectOnFootType  0x0218AEAC  thumb
 *   FIELD_EVENT_CHECK_SetEntranceFromRailConnect  0x0218B2A8  thumb
 *   FIELD_EVENT_CHECK_StartRailConnectEvent  0x0218B2E8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04982.h"

typedef unsigned short u16;

typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
struct Q;
extern int EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(char *p, struct Q *q);
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern int EVENTDATA_SYSTEM_IsConnectDisabled(u16 *p);
extern int FIELD_EVENT_CHECK_IsConnectOnFootType(u8 *p);
extern void FIELD_EVENT_CHECK_SetEntranceFromRailConnect(char *p, int s, u16 *v);
extern int FIELD_EVENT_CHECK_StartRailConnectEvent(char *p, void *x, int a, int *b);

int FIELD_EVENT_CHECK_CheckRailConnect(char *p, void *unused, void *x)
{
    int buf[2];
    int r4;
    void *r6;

    FLDMMDL_RAIL_GetNextLocation(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(x)), buf);
    r4 = EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(((struct Obj04982 *)p)->fC, (struct Q *)buf);
    if (r4 == 0xFFFF)
        return 0;
    r6 = EVENTDATA_SYSTEM_GetConnectData(((struct Obj04982 *)p)->fC, (u16)r4);
    if (EVENTDATA_SYSTEM_IsConnectDisabled(r6) == 1 || FIELD_EVENT_CHECK_IsConnectOnFootType(r6) == 0)
        return 0;
    FIELD_EVENT_CHECK_SetEntranceFromRailConnect(p, r4, (u16 *)buf);
    return FIELD_EVENT_CHECK_StartRailConnectEvent(p, x, r4, buf);
}
