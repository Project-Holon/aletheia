/*
 * function: WIFIBATTLEMATCH_NET_StopMatchmaking
 * address:  0x021DA390
 * packet:   pkt_021DA390
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFIBATTLEMATCH_NET_SetTimingSyncRange  0x021D9ED4  thumb
 *   WIFIBATTLEMATCH_NET_IsTimingSyncRange  0x021D9EEC  thumb
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *
 * Link shutdown sequence stepped by the word at +0x154: sync 0x18, wait for the sync (600 frame timeout on +0x1a0), stop the two link services, wait 30 frames on +0x134, restart the parent service, then report done (1).
 */
#include "../include/Obj02513.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern void WIFIBATTLEMATCH_NET_SetTimingSyncRange(char *obj, u32 v);
extern int WIFIBATTLEMATCH_NET_IsTimingSyncRange(char *obj);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);

int WIFIBATTLEMATCH_NET_StopMatchmaking(char *obj)
{
    switch (((struct Obj02513 *)obj)->f154) {
    case 0:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(obj, 0x18);
        ((struct Obj02513 *)obj)->f1A0 = 0;
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(obj) != 0)
            (((struct Obj02513 *)obj)->f154)++;
        else if ((((struct Obj02513 *)obj)->f1A0)++ > 600)
            (((struct Obj02513 *)obj)->f154)++;
        break;
    case 2:
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        ((struct Obj02513 *)obj)->f134 = 0;
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 3:
        if ((((struct Obj02513 *)obj)->f134)++ > 30)
            (((struct Obj02513 *)obj)->f154)++;
        break;
    case 4:
        GFL_NET_STATE_WifiDisconnect(1);
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
