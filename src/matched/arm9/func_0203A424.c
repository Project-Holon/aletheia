/*
 * unit:     no
 * function: GFL_NET_HANDLE_SetUserInfo
 * address:  0x0203A424
 * packet:   pkt_02039CD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 */
#include "../include/Obj06942.h"

struct Entry;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c)
{
    if (p == 0)
        return;
    ((struct Obj06942 *)p)->f46 = (unsigned short)(a + (b << 8));
    p[0x48] = (char)c;
    if (GFL_NET_HANDLE_GetNetHandleID((struct Entry *)p) == 0xff)
        p[0x49] = 0;
    else
        p[0x49] = 1;
}
