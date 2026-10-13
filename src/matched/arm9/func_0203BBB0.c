/*
 * function: GFL_NET_STATE_ChangeoverRestart
 * address:  0x0203BBB0
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
 *   GFL_NET_STATE_ChangeoverStopParent  0x0203B48C  arm
 *   GFL_NET_STATE_ChangeoverParentMain  0x0203B5D4  arm
 *   GFL_NET_STATE_ChangeoverStopChild  0x0203B90C  arm
 *   GFL_NET_STATE_ChangeoverChildMain  0x0203B950  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Two presets that differ only in the state byte they match and the handler
 * they advertise.  Each test is a conjunction of the state byte and the
 * eight-byte pointer stored beside it, and the first arm also refuses when
 * the vtable's +0x10 hook answers zero.
 *
 * The four code addresses are declared as the functions they are: written as
 * integer literals the front end folds two nearby ones into one pool word plus
 * a `sub`, which is four bytes shorter than the original.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverRestart.c \
 *       --func GFL_NET_STATE_ChangeoverRestart --addr 0x0203BBB0 --cc 1.1p1 --arm
 */
#include "../include/Obj06945.h"
#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

struct Slot;
extern void *GFL_NET_GetSession(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void GFL_NET_STATE_ChangeoverChildMain(u8 *p);
extern void GFL_NET_STATE_ChangeoverStopChild(void);
extern void GFL_NET_STATE_ChangeoverParentMain(struct Slot *p);
extern void GFL_NET_STATE_ChangeoverStopParent(void);

void GFL_NET_STATE_ChangeoverRestart(u32 a)
{
    u8 *s = GFL_NET_GetSession();
    u8 *g;

    g = ((u8 *)_pNetState);
    if (g[0x56] == 2 && ((struct Obj06945 *)g)->f8 == (u32)GFL_NET_STATE_ChangeoverChildMain) {
        if ((*(u32 (**)(u32, u32))(*(u32 *)(s + 0x340) + 0x10))(1, 0) != 0) {
            GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)GFL_NET_STATE_ChangeoverStopChild, 0, 0x3E0);
        }
    }

    g = ((u8 *)_pNetState);
    if (g[0x56] == 1 && ((struct Obj06945 *)g)->f8 == (u32)GFL_NET_STATE_ChangeoverParentMain) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)g, (void *)GFL_NET_STATE_ChangeoverStopParent, 0, 0x3E9);
    }
}
