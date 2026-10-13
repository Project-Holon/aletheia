/*
 * function: WIFICLUB_StateSendChoiceMessage
 * address: 0x021C13D0
 * packet: pkt_ov099_021C13D0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_LoadPickedRegulation 0x021BCBD8 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
#include "../include/Obj04417.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 a, b; unsigned c; } Request;
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern int WIFICLUB_GetStatusPhase(char *, void *);
extern unsigned WIFICLUB_LoadPickedRegulation(char *, int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int WIFICLUB_StateSendChoiceMessage(char *p, int ret)
{
    Request request;
    WIFICLUB_GetStatusKind(p, ((struct Obj04417 *)p)->f8);
    request.a = WIFICLUB_GetStatusPhase(p, ((struct Obj04417 *)p)->f8);
    if (((struct Obj04417 *)p)->f1356 != 0) {
        request.b = ((struct Obj04417 *)p)->f1356 - 1;
        ((struct Obj04417 *)p)->f1356 = 0;
    } else {
        request.b = *((u8 *)((struct Obj04417 *)p)->f248 + 0x46);
    }
    request.c = WIFICLUB_LoadPickedRegulation(p, 1);
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa03, 8, (u32)(&request)) != 0)
        ((struct Obj04417 *)p)->f1CC = 43;
    return ret;
}
