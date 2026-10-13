/*
 * function: GFL_NET_STATE_ChangeoverStopChild
 * address:  0x0203B90C
 * packet:   pkt_0203B6EC
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
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStopChild.c \
 *       --func GFL_NET_STATE_ChangeoverStopChild --addr 0x0203B90C --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern u8 *GFL_NET_GetSession(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_ChangeoverStopChild(void)
{
    if ((*(u32 (**)(void))(*(u32 *)(GFL_NET_GetSession() + 0x340) + 0x78))() == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203B6EC, 0, 0x371);
}
