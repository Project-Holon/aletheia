/*
 * unit:     no
 * function: GFL_NET_STATE_WifiStopError
 * address:  0x0203C0B4
 * packet:   pkt_0203B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_SetNoChildError  0x020394DC  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 */
#include "../include/Obj15962.h"

typedef unsigned char  u8;
extern void *GFL_NET_GetSession(void);
extern void GFL_NET_SYSTEM_SetNoChildError(u8 v);
void GFL_NET_STATE_WifiStopError(void)
{
    int *r = GFL_NET_GetSession();
    void (*fn)(int);
    GFL_NET_SYSTEM_SetNoChildError(1);
    fn = *(void (**)(int))(((struct Obj15962 *)r)->f340 + 0xc);
    fn(0);
}
