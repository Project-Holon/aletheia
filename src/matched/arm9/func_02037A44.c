/*
 * unit:     no
 * function: GFL_NET_SYSTEM_SetDeviceMode
 * address:  0x02037A44
 * packet:   pkt_02037234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj15930.h"

extern void *GFL_NET_GetSession(void);
void GFL_NET_SYSTEM_SetDeviceMode(int a)
{
    int *r = GFL_NET_GetSession();
    int *t = *(int * *)&((struct Obj15930 *)r)->f340;
    if (t == 0)
        return;
    ((void (*)(int))t[0x30])(a);
}
