/*
 * function: WIFICLUB_StateRestartInvite
 * address:  0x021BC228
 * packet:   pkt_ov099_021BC228
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_NotifyUserEvent  0x0203D1E8  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   WIFICLUB_SetPartnerNameWord  0x021BA874  thumb  ov099
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   WIFICLUB_ResetTimeIcon  0x021BC090  thumb  ov099
 */
#include "../include/Obj06354.h"

typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_NotifyUserEvent(int a, int b);
extern int GFL_NET_IsParentAid(int a);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, unsigned int b, unsigned int c);
extern void WIFICLUB_SetPartnerNameWord(void *p, int id);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
extern void WIFICLUB_ResetTimeIcon(void *p);

int WIFICLUB_StateRestartInvite(char *p, int r)
{
    if (GFL_NET_IsParentAid(GFL_NET_NotifyUserEvent((int)GFL_NET_HANDLE_GetCurrentHandle(), 0)) != 0) {
        ((struct Obj06354 *)p)->f135C = 3;
        WIFICLUB_SetPartnerNameWord(p, ((struct Obj06354 *)p)->f242 - 1);
        WIFICLUB_ShowStreamedMessage(p, 0x60, 0);
        ((struct Obj06354 *)p)->f1CC = 0x45;
    } else {
        ((struct Obj06354 *)p)->f135C = 4;
        WIFICLUB_ShowStreamedMessage(p, 0x4C, 0);
        WIFICLUB_ResetTimeIcon(p);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1B, 0xA);
        ((struct Obj06354 *)p)->f1CC = 0x49;
    }
    return r;
}
