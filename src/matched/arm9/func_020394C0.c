/*
 * function: GFL_NET_SYSTEM_IsSendQueueEmpty
 * address:  0x020394C0
 * packet:   pkt_020394C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetSys     0x021469D0  data
 *   GFL_NET_QUEUE_IsEmpty  0x020366A8  arm
 *
 * Leaf that saves no lr: tail-calls GFL_NET_QUEUE_IsEmpty on the 0xCC queue of the
 * net_system record (docs/families/net_system.h, fCC).  Reached only through
 * the long-branch veneer at 0x0203D56C.
 */

#include "../include/G_LinkState.h"

typedef unsigned char u8;

struct Conn;
extern int GFL_NET_QUEUE_IsEmpty(struct Conn *p);
extern struct LinkState *_pNetSys;

int GFL_NET_SYSTEM_IsSendQueueEmpty(void)
{
    return GFL_NET_QUEUE_IsEmpty((struct Conn *)(((u8 *)_pNetSys) + 0xCC));
}
