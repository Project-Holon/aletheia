/*
 * function: GFL_NET_STATE_InitParent
 * address:  0x0203B2D0
 * packet:   pkt_0203B2FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_STATE_StartParent  0x0203B258  arm
 */

#include "../include/G_Sys.h"

typedef unsigned int u32;

struct Sys;

extern struct Sys *_pNetState;
extern void GFL_NET_STATE_StartParent(void);

typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_InitParent(u32 val)
{
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((struct Sys *)_pNetState), GFL_NET_STATE_StartParent, 0, 0x222);
}
