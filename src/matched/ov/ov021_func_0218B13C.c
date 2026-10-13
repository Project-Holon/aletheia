/*
 * function: FIELD_EVENT_CHECK_CheckRailConnectFront
 * address:  0x0218B13C
 * packet:   pkt_ov021_0218B13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   EVENTDATA_SYSTEM_SearchConnectIdByRailLocation  0x02162598  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_IsConnectDisabled  0x021626EC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   FIELD_EVENT_CHECK_IsConnectExitDir  0x0218AECC  thumb  ov021
 *   FIELD_EVENT_CHECK_SetEntranceFromRailConnect  0x0218B2A8  thumb  ov021
 *   FIELD_EVENT_CHECK_StartRailConnectEvent  0x0218B2E8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04983.h"

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
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);
extern int FIELD_EVENT_CHECK_IsConnectExitDir(char *a0, int a1);
extern void FIELD_EVENT_CHECK_SetEntranceFromRailConnect(char *p, int s, u16 *v);
extern int FIELD_EVENT_CHECK_StartRailConnectEvent(char *p, void *x, int a, int *b);

int FIELD_EVENT_CHECK_CheckRailConnectFront(char *p, void *unused, void *x, int *alt)
{
    int buf[2];
    int id;
    void *o;

    FLDMMDL_RAIL_GetNextLocation(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(x)), buf);
    id = EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(((struct Obj04983 *)p)->fC, (struct Q *)buf);
    if (id != 0xFFFF) {
        o = EVENTDATA_SYSTEM_GetConnectData(((struct Obj04983 *)p)->fC, (u16)id);
        if (EVENTDATA_SYSTEM_IsConnectDisabled(o) == 0 && FIELD_EVENT_CHECK_IsConnectExitDir(o, ((struct Obj04983 *)p)->f24) != 0
            && EVENTDATA_SYSTEM_GetConnectExitType(o) == 1) {
            FIELD_EVENT_CHECK_SetEntranceFromRailConnect(p, id, (u16 *)buf);
            return FIELD_EVENT_CHECK_StartRailConnectEvent(p, x, id, buf);
        }
    }
    id = EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(((struct Obj04983 *)p)->fC, (struct Q *)alt);
    if (id == 0xFFFF)
        return 0;
    o = EVENTDATA_SYSTEM_GetConnectData(((struct Obj04983 *)p)->fC, (u16)id);
    if (EVENTDATA_SYSTEM_IsConnectDisabled(o) == 0 && FIELD_EVENT_CHECK_IsConnectExitDir(o, ((struct Obj04983 *)p)->f24) != 0) {
        FIELD_EVENT_CHECK_SetEntranceFromRailConnect(p, id, (u16 *)buf);
        return FIELD_EVENT_CHECK_StartRailConnectEvent(p, x, id, buf);
    }
    return 0;
}
