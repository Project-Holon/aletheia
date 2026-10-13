/*
 * function: GFL_NET_STATE_WifiMatchDisconnect
 * address:  0x0203C494
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
 *   GFL_NET_STATE_WifiConnected  0x0203C464  arm
 *   GFL_NET_STATE_WifiError  0x0203C05C  arm
 *   GFL_NET_SYSTEM_ResetAll  0x02037D78  arm
 *   GFL_NET_SYSTEM_SetNoChildError  0x020394DC  arm
 *   GFL_NET_HANDLE_InitWork  0x02039834  arm
 *   GFL_NET_HANDLE_ExitWork  0x020398B4  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * The other half of the connect/disconnect pair whose partner is
 * src/matched/GFL_NET_STATE_WifiDisconnect.c: it turns the state byte at +0x4B into the
 * vtable's +0x54 hook, then either starts the link layer or, when the +0x0C
 * hook reports a negative result, files line 0x655.
 *
 * `v` is materialised as 0 before the first call and raised to 1 by
 * `moveq` on the state byte's own compare, so the hook's first argument
 * shares a register with the loop's zero rather than being rematerialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WifiMatchDisconnect.c \
 *       --func GFL_NET_STATE_WifiMatchDisconnect --addr 0x0203C494 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern void *GFL_NET_GetSession(void);
extern int GFL_NET_STATE_WifiConnected(int a0, int a1, int a2, int a3);
extern void GFL_NET_STATE_WifiError(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void GFL_NET_SYSTEM_SetNoChildError(u8 v);
extern void GFL_NET_SYSTEM_ResetAll(void);
extern void GFL_NET_HANDLE_ExitWork(u32 a);
extern void GFL_NET_HANDLE_InitWork(u32 a);

void GFL_NET_STATE_WifiMatchDisconnect(u8 *p)
{
    u8 *s = GFL_NET_GetSession();
    u32 v = 0;

    GFL_NET_SYSTEM_SetNoChildError(0);

    if (p[0x4B] == 0)
        v = 1;

    if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x54))(v, 0) != 0) {
        GFL_NET_SYSTEM_ResetAll();
        GFL_NET_HANDLE_ExitWork((u32)s);
        GFL_NET_HANDLE_InitWork((u32)s);
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)GFL_NET_STATE_WifiConnected, 0, 0x64F);
    } else if ((*(int (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(0) < 0) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)GFL_NET_STATE_WifiError, 0, 0x655);
    }
}
