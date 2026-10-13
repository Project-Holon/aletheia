/*
 * function: WIFICLUB_StateSendSeatRequest
 * address: 0x021BD8D8
 * packet: pkt_ov099_021BD8D8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_SetStatusModeFlag 0x021C2864 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 * return-evidence: caller consumes r0 after both ARM9 calls despite legacy void declarations; four original outgoing registers retained.
 */
#include "../include/Obj07951.h"
#include "../include/Obj22042.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 a, b; } Request;
extern u8 WIFICLUB_GetStatusPhase(int, void *);
extern void WIFICLUB_SetStatusModeFlag(void *, u8);
typedef unsigned int   u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int WIFICLUB_StateSendSeatRequest(char *p, int ret)
{
    Request request;
    request.a = WIFICLUB_GetStatusPhase((int)p, ((struct Obj07951 *)p)->f8);
    request.b = 1 - ((struct Obj22042 *)(*(char * *)&((struct Obj07951 *)p)->f248))->f46;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa03, 4, (unsigned)&request) != 0) {
        ((struct Obj07951 *)p)->f1CC = 0x81;
        WIFICLUB_SetStatusModeFlag(((struct Obj07951 *)p)->f8, request.b);
    }
    return ret;
}
