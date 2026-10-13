/*
 * function: FIELD_EVENT_CHECK_FindGridConnectId
 * address:  0x0218AE04
 * packet:   pkt_ov021_0218AE04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the current entry id from EVENTDATA_SYSTEM_SearchConnectIdByGridPos when it is usable
 * (FIELD_EVENT_CHECK_IsConnectOnFootType or FIELD_EVENT_CHECK_IsConnectExitDir accepts it), else 0xFFFF.
 *
 * symbols:
 *   EVENTDATA_SYSTEM_SearchConnectIdByGridPos  0x02162564  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   FIELD_EVENT_CHECK_IsConnectOnFootType  0x0218AEAC  thumb
 *   FIELD_EVENT_CHECK_IsConnectExitDir  0x0218AECC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00705.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Q;
extern int EVENTDATA_SYSTEM_SearchConnectIdByGridPos(char *p, struct Q *q);
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern int FIELD_EVENT_CHECK_IsConnectOnFootType(u8 *p);
extern int FIELD_EVENT_CHECK_IsConnectExitDir(char *a0, int a1);

u32 FIELD_EVENT_CHECK_FindGridConnectId(u8 *p, void *arg)
{
    u32 id = (u32)EVENTDATA_SYSTEM_SearchConnectIdByGridPos(((struct Obj00705 *)p)->fC, arg);
    void *obj;

    if (id == 0xFFFF)
        return 0xFFFF;
    obj = EVENTDATA_SYSTEM_GetConnectData(((struct Obj00705 *)p)->fC, (u16)id);
    if (!FIELD_EVENT_CHECK_IsConnectOnFootType(obj) && !FIELD_EVENT_CHECK_IsConnectExitDir(obj, ((struct Obj00705 *)p)->f24))
        return 0xFFFF;
    return id;
}
