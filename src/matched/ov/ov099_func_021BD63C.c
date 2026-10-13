/*
 * function: WIFICLUB_StateWaitSyncAndResume
 * address: 0x021BD63C
 * packet: pkt_ov099_021BD63C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 */
#include "../include/Obj07950.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
int WIFICLUB_StateWaitSyncAndResume(char *p, int v)
{
    int state;
    WIFICLUB_UpdateTalkStream(p);
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1a, 10) != 0) {
        state = ((struct Obj07950 *)p)->f1357;
        if (state != 0) ((struct Obj07950 *)p)->f1CC = state;
        else ((struct Obj07950 *)p)->f1CC = 0x15;
        ((struct Obj07950 *)p)->f1357 = 0;
    }
    return v;
}
