/*
 * function: GFL_NET_STATE_WifiDisconnect
 * address:  0x0203C554
 * packet:   pkt_0203C494
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
 *   GFL_NET_STATE_WifiMatchDisconnect  0x0203C494  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiDisconnect.c \
 *       --func GFL_NET_STATE_WifiDisconnect --addr 0x0203C554 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern u16 func_02039338(void);
extern void GFL_NET_STATE_WifiMatchDisconnect(u8 *p);

void GFL_NET_STATE_WifiDisconnect(u32 a)
{
    u8 *p = ((u8 *)_pNetState);

    if (p == 0)
        return;

    if (a != 0) {
        if (func_02039338() == 0)
            ((u8 *)_pNetState)[0x4B] = 0;
        else
            ((u8 *)_pNetState)[0x4B] = 1;
    } else {
        p[0x4B] = 0;
    }

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C494, 0, 0x671);
    GFL_NET_STATE_WifiMatchDisconnect((u8 *)((u32)((u8 *)_pNetState)));
}
