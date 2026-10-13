/*
 * function: GFL_NET_SYSTEM_IsSendQueueEntry
 * address:  0x02039468
 * packet:   pkt_02039468
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _pNetSys   0x021469D0  data
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_QUEUE_IsCommandQueued 0x02036B98 arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct LinkState *_pNetSys;
extern void *GFL_NET_GetInitParam(void);
extern int GFL_NET_QUEUE_IsCommandQueued(char *p, int v);

void GFL_NET_SYSTEM_IsSendQueueEntry(u32 a, u32 b)
{
    u8 *s = (u8 *)GFL_NET_GetInitParam();

    if (s[0x64] != 0 && b == 0xff) {
        GFL_NET_QUEUE_IsCommandQueued((char *)(((u8 *)_pNetSys) + 0xf4), a);
    } else {
        GFL_NET_QUEUE_IsCommandQueued((char *)(((u8 *)_pNetSys) + 0xcc), a);
    }
}
