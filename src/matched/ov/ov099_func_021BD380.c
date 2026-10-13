/*
 * function: WIFICLUB_StateSyncAfterPartySend
 * address: 0x021BD380
 * packet: pkt_ov099_021BD380
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
int WIFICLUB_StateSyncAfterPartySend(char *p, int v)
{
    if (WIFICLUB_UpdateTalkStream(p) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 10);
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x68;
    }
    return v;
}
