/*
 * function: GFL_NET_STATE_WifiMatchWait
 * address:  0x0203C7E0
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
 *   GFL_NET_STATE_SetWifiErrorCode  0x0203C0DC  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiMatchWait.c \
 *       --func GFL_NET_STATE_WifiMatchWait --addr 0x0203C7E0 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern void *GFL_NET_GetSession(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void GFL_NET_STATE_SetWifiErrorCode(u8 *p, u32 v);

void GFL_NET_STATE_WifiMatchWait(u8 *p)
{
    u8 *s = GFL_NET_GetSession();
    int r = (*(int (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0);

    if (r < 0) {
        GFL_NET_STATE_SetWifiErrorCode(p, (u32)r);
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C05C, 0, 0x72E);
    } else if (r > 0) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C464, 0, 0x737);
    }
}
