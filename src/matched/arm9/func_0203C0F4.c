/*
 * function: GFL_NET_STATE_WifiLoginMain
 * address:  0x0203C0F4
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
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_STATE_SetWifiErrorCode  0x0203C0DC  arm
 *   GFL_NET_STATE_WifiStopError  0x0203C0B4  arm
 *   GFL_NET_STATE_WifiLoggedOut  0x0203C060  arm
 *   GFL_NET_STATE_WifiFatal  0x0203C064  arm
 *   GFL_NET_STATE_WifiError  0x0203C05C  arm
 */
#include "../include/Obj11369.h"
#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern struct Sys *_pNetState;
extern void *GFL_NET_GetSession(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void GFL_NET_STATE_SetWifiErrorCode(u8 *p, u32 v);
extern void GFL_NET_STATE_WifiStopError(void);
extern void GFL_NET_STATE_WifiLoggedOut(void);
extern void GFL_NET_STATE_WifiFatal(void);
extern void GFL_NET_STATE_WifiError(void);

void GFL_NET_STATE_WifiLoginMain(void *p)
{
    u8 *net = GFL_NET_GetSession();
    u32 *obj = *(u32 * *)&((struct Obj11369 *)net)->f340;
    s32 res = ((s32 (*)(int))obj[3])(0);

    if (res == 1000) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(int *)&_pNetState), (void *)GFL_NET_STATE_WifiStopError, 0, 1403);
        return;
    }

    obj = *(u32 * *)&((struct Obj11369 *)net)->f340;
    if (((s32 (*)(void))obj[0xac / 4])() != 0) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(int *)&_pNetState), (void *)GFL_NET_STATE_WifiStopError, 0, 1407);
        return;
    }

    if (res == 1007) {
        return;
    }

    if (res == 1001) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(int *)&_pNetState), (void *)GFL_NET_STATE_WifiLoggedOut, 0, 1413);
        return;
    }

    if (res == 1002) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(int *)&_pNetState), (void *)GFL_NET_STATE_WifiFatal, 0, 1416);
        return;
    }

    if (res >= 10) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(int *)&_pNetState), (void *)GFL_NET_STATE_WifiFatal, 0, 1420);
        return;
    }

    if (res >= 0) {
        return;
    }

    GFL_NET_STATE_SetWifiErrorCode(p, res);
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(int *)&_pNetState), (void *)GFL_NET_STATE_WifiError, 0, 1424);
}
