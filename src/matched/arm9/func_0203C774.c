/*
 * function: GFL_NET_STATE_WifiLogout
 * address:  0x0203C774
 * packet:   pkt_0203C65C
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
 *   UI_ClearFlags39Global  0x020351A0  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiLogout.c \
 *       --func GFL_NET_STATE_WifiLogout --addr 0x0203C774 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern void *GFL_NET_GetSession(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern int UI_ClearFlags39Global(u32 v);

void GFL_NET_STATE_WifiLogout(u32 v)
{
    u8 *s;

    if (((u8 *)_pNetState) == 0)
        return;

    s = GFL_NET_GetSession();
    UI_ClearFlags39Global(1);
    *(u32 *)(((u8 *)_pNetState) + 0x28) = v;
    (*(void (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x54))(1, 0);

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C710, 5, 0x719);
}
