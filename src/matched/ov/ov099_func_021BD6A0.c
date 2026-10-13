/*
 * function: WIFICLUB_StateStartLeaveSync
 * address: 0x021BD6A0
 * packet: pkt_ov099_021BD6A0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj13691.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WIFICLUB_SetOwnStatusAndPublish(char *, int, int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, u32, u32);
int WIFICLUB_StateStartLeaveSync(char *p, int v)
{
    WIFICLUB_SetOwnStatusAndPublish(p, 1, 2);
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 10);
    ((struct Obj13691 *)p)->f135C = 0;
    ((struct Obj13691 *)p)->f1CC = 0x9c;
    return v;
}
