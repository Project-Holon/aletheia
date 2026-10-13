/*
 * function: WIFICLUB_StateWaitSyncAndReturnToIdle
 * address: 0x021BD678
 * packet: pkt_ov099_021BD678
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, u32, u32);
int WIFICLUB_StateWaitSyncAndReturnToIdle(char *p, int v)
{
    WIFICLUB_UpdateTalkStream(p);
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10) != 0) {
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x48;
    }
    return v;
}
