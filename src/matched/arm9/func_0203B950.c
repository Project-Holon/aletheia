/*
 * function: GFL_NET_STATE_ChangeoverChildMain
 * address:  0x0203B950
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
 *   GFL_NET_STATE_ChangeoverStopChildDevice  0x0203BCE0  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverChildMain.c \
 *       --func GFL_NET_STATE_ChangeoverChildMain --addr 0x0203B950 --cc 1.1p1 --arm
 */
#include "../include/Obj08841.h"
#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern u16 func_02039338(void);
extern void GFL_NET_STATE_ChangeoverStopChildDevice(u8 *p);

void GFL_NET_STATE_ChangeoverChildMain(u8 *p)
{
    if (func_02039338() != 0) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203B758, 0, 0x383);
        return;
    }

    if (p[0x56] == 2)
        return;

    if (((struct Obj08841 *)p)->f46 != 0) {
        (((struct Obj08841 *)p)->f46)--;
        return;
    }

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203BCE0, 0, 0x390);
    GFL_NET_STATE_ChangeoverStopChildDevice(p);
}
