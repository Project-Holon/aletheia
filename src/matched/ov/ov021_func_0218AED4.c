/*
 * function: FIELD_EVENT_CHECK_CheckGridConnectFront
 * address:  0x0218AED4
 * packet:   pkt_ov021_0218AED4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EVENT_CHECK_GetFrontPos  0x0218AE48  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FIELD_EVENT_CHECK_FindGridConnectId  0x0218AE04  thumb  ov021
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_IsConnectDisabled  0x021626EC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   FIELD_EVENT_CHECK_SetEntranceFromGridConnect  0x0218ADC8  thumb  ov021
 *   FIELD_EVENT_CHECK_StartConnectEvent  0x0218AD80  thumb  ov021
 */
#include "../include/Obj00705.h"

typedef unsigned short u16;

typedef struct Vec { int x, y, z; } Vec;

struct Obj;
extern void FIELD_EVENT_CHECK_GetFrontPos(struct Obj *p, struct Vec *out);
extern unsigned int FIELDMAP_GetG3dMapper(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern u32 FIELD_EVENT_CHECK_FindGridConnectId(u8 *p, void *arg);
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern int EVENTDATA_SYSTEM_IsConnectDisabled(u16 *p);
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);
extern void FIELD_EVENT_CHECK_SetEntranceFromGridConnect(u8 *p, int id, u32 *pos);
extern int FIELD_EVENT_CHECK_StartConnectEvent(void *p, void *a, int id, Vec *pos);

int FIELD_EVENT_CHECK_CheckGridConnectFront(char *p, int unused, void *a)
{
    Vec v;
    int id;
    void *o;

    FIELD_EVENT_CHECK_GetFrontPos((struct Obj *)p, &v);
    if ((MAP_ATTR_GetFlags(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(a), &v)) & 1) == 0)
        return 0;
    id = (int)FIELD_EVENT_CHECK_FindGridConnectId((u8 *)p, *(Vec * *)&((struct Obj00705 *)p)->f34);
    if (id != 0xFFFF) {
        o = EVENTDATA_SYSTEM_GetConnectData(((struct Obj00705 *)p)->fC, (u16)id);
        if (EVENTDATA_SYSTEM_IsConnectDisabled(o) == 0 && EVENTDATA_SYSTEM_GetConnectExitType(o) == 1) {
            FIELD_EVENT_CHECK_SetEntranceFromGridConnect((u8 *)p, id, (u32 *)(*(Vec * *)&((struct Obj00705 *)p)->f34));
            return FIELD_EVENT_CHECK_StartConnectEvent(p, a, id, *(Vec * *)&((struct Obj00705 *)p)->f34);
        }
    }
    id = (int)FIELD_EVENT_CHECK_FindGridConnectId((u8 *)p, &v);
    if (id != 0xFFFF) {
        if (EVENTDATA_SYSTEM_IsConnectDisabled(EVENTDATA_SYSTEM_GetConnectData(((struct Obj00705 *)p)->fC, (u16)id)) == 0) {
            FIELD_EVENT_CHECK_SetEntranceFromGridConnect((u8 *)p, id, (u32 *)(*(Vec * *)&((struct Obj00705 *)p)->f34));
            return FIELD_EVENT_CHECK_StartConnectEvent(p, a, id, &v);
        }
    }
    return 0;
}
