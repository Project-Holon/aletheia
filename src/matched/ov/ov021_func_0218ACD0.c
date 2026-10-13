/*
 * function: FIELD_EVENT_CHECK_CheckGridConnect
 * address:  0x0218ACD0
 * packet:   pkt_ov021_0218ACD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * For a usable entry id (FIELD_EVENT_CHECK_FindGridConnectId), unless ov010 EVENTDATA_SYSTEM_IsConnectDisabled reports
 * kind 1 or FIELD_EVENT_CHECK_IsConnectOnFootType rejects it, builds its record (FIELD_EVENT_CHECK_SetEntranceFromGridConnect) and
 * dispatches it (FIELD_EVENT_CHECK_StartConnectEvent).
 *
 * Blocker: the call to 0x021626EC is the one wildcard. That address is Thumb
 * code in ov010 (ldrh r2, [r0]; ldr r1, [pc, #0x14]; ...) with no func_
 * label, so no class attests it. It closes once ov010 0x021626EC is labelled.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_IsConnectDisabled  0x021626EC  thumb  ov010
 *   FIELD_EVENT_CHECK_FindGridConnectId  0x0218AE04  thumb
 *   FIELD_EVENT_CHECK_IsConnectOnFootType  0x0218AEAC  thumb
 *   FIELD_EVENT_CHECK_SetEntranceFromGridConnect  0x0218ADC8  thumb
 *   FIELD_EVENT_CHECK_StartConnectEvent  0x0218AD80  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00705.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 FIELD_EVENT_CHECK_FindGridConnectId(u8 *p, void *arg);
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern int EVENTDATA_SYSTEM_IsConnectDisabled(u16 *p);
extern int FIELD_EVENT_CHECK_IsConnectOnFootType(u8 *p);
extern void FIELD_EVENT_CHECK_SetEntranceFromGridConnect(u8 *p, int id, u32 *pos);
extern int FIELD_EVENT_CHECK_StartConnectEvent(u8 *p, void *a, int id, void *arg);

int FIELD_EVENT_CHECK_CheckGridConnect(u8 *p, void *a, void *arg)
{
    u32 id = FIELD_EVENT_CHECK_FindGridConnectId(p, arg);
    void *obj;

    if (id == 0xFFFF)
        return 0;
    obj = EVENTDATA_SYSTEM_GetConnectData(((struct Obj00705 *)p)->fC, (u16)id);
    if (EVENTDATA_SYSTEM_IsConnectDisabled(obj) == 1 || !FIELD_EVENT_CHECK_IsConnectOnFootType(obj))
        return 0;
    FIELD_EVENT_CHECK_SetEntranceFromGridConnect(p, id, arg);
    return FIELD_EVENT_CHECK_StartConnectEvent(p, a, id, arg);
}
