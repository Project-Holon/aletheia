/*
 * function: GFL_NET_STATE_WifiLoginStart
 * address:  0x0203C238
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
 *   GFL_NET_SYSTEM_ResetAll  0x02037D78  arm
 *   GFL_NET_HANDLE_InitWork  0x02039834  arm
 *   GFL_NET_HANDLE_ExitWork  0x020398B4  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiLoginStart.c \
 *       --func GFL_NET_STATE_WifiLoginStart --addr 0x0203C238 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;
extern void *GFL_NET_GetSession(void);
extern void *GFL_NET_GetInitParam(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void GFL_NET_SYSTEM_ResetAll(void);
extern void GFL_NET_HANDLE_ExitWork(u32 a);
extern void GFL_NET_HANDLE_InitWork(u32 a);

void GFL_NET_STATE_WifiLoginStart(s8 *p)
{
    u8 *s = GFL_NET_GetSession();
    u8 *q = GFL_NET_GetInitParam();

    if ((*(u32 (**)(int, u32, u32))(*(u32 *)(s + 0x340) + 0x50))(p[0x48], q[0x60], 0) != 0)
        return;

    GFL_NET_SYSTEM_ResetAll();
    GFL_NET_HANDLE_ExitWork((u32)s);
    GFL_NET_HANDLE_InitWork((u32)s);
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C0F4, 0, 0x5AC);
}
