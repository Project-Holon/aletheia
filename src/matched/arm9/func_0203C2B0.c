/*
 * function: GFL_NET_STATE_WifiEnterLogin
 * address:  0x0203C2B0
 * packet:   pkt_0203C0F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_SYSTEM_SetDeviceOption  0x0203778C  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiEnterLogin.c \
 *       --func GFL_NET_STATE_WifiEnterLogin --addr 0x0203C2B0 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern u32 GFL_NET_SYSTEM_SetDeviceOption(u32 p);

int GFL_NET_STATE_WifiEnterLogin(int a)
{
    if (a != -1) {
        if (GFL_NET_SYSTEM_SetDeviceOption((u32)a) == 0)
            return 0;
    }

    ((u8 *)_pNetState)[0x48] = (u8)a;
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C238, 0, 0x5C4);
    return 1;
}
