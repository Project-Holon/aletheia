/*
 * function: GFL_NET_STATE_ChangeoverParentMain
 * address:  0x0203B5D4
 * packet:   pkt_0203B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     promoted MATCH -> EXACT on 2026-09-21 (family wave 4).
 *
 * THE FIX WAS THE DECLARATION, NOT THE C.  The body is byte-identical to the
 * parked version; only the +0x00a4 site's spelling changed.  The earlier
 * header read that word as a module-name STRING (`str_0203B52C`, kind
 * `data`) and concluded no class could attest it.  It is not a string: it is
 * the CODE ADDRESS of GFL_NET_STATE_ChangeoverParentConnectWait, handed to GFL_NET_STATE_ChangeStateDebug as the
 * reporting call's identifier tag, exactly the way GFL_NET_STATE_ConnectMac hands it
 * the no-op at 0x0203B018 and GFL_NET_STATE_ChangeoverParentConnectWait hands it GFL_NET_STATE_ChangeoverStopParentRetry.  Spelt
 * `GFL_NET_STATE_ChangeoverParentConnectWait 0x0203B52C arm` and passed as `(void *)GFL_NET_STATE_ChangeoverParentConnectWait`, the
 * site resolves `sole-ref x1` -- sole-ref/code, since 0x0203B52C is exactly
 * a traced ARM function start, and that sub-kind needs no outside branch.
 *
 * The companion site at +0x00ac (0x0203B48C) already resolved `literal x8`
 * and is unchanged.
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_SYSTEM_GetChildBitmap  0x020393A8  arm
 *   func_0203D798  0x0203D798  arm
 *   GFL_NET_STATE_ChangeParentWait  0x0203B2A8  arm
 *   GFL_NET_CallDeviceReadyFunc  0x0203D700  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_ChangeoverParentConnectWait  0x0203B52C  arm
 *   str_0203B48C   0x0203B48C  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverParentMain.c \
 *       --func GFL_NET_STATE_ChangeoverParentMain --addr 0x0203B5D4 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Sys *_pNetState;
struct Slot;
extern void GFL_NET_STATE_ChangeoverParentConnectWait(struct Slot *p);
extern char str_0203B48C[];

extern void *GFL_NET_GetSession(void);
extern int GFL_NET_SYSTEM_GetChildBitmap(void);
extern u8   *func_0203D798(void);
extern void GFL_NET_STATE_ChangeParentWait(int a0);
extern void  GFL_NET_CallDeviceReadyFunc(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

struct Vt {
    u8  pad_00[0x38];
    u32 (*f38)(u32 a);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
};

struct Slot {
    u8  pad_00[0x46];
    u16 f46;
    u8  pad_48[0xe];
    u8  f56;
};

void GFL_NET_STATE_ChangeoverParentMain(struct Slot *p)
{
    struct Obj *q = (struct Obj *)GFL_NET_GetSession();

    if (GFL_NET_SYSTEM_GetChildBitmap() != 0) {
        GFL_NET_STATE_ChangeParentWait(*(u16 *)(func_0203D798() + 0x56));
        GFL_NET_CallDeviceReadyFunc();
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(u32 *)&_pNetState), (void *)GFL_NET_STATE_ChangeoverParentConnectWait, 0, 0x2c1);
        return;
    }
    if (p->f56 == 1)
        return;
    if (q->f340->f38(0) == 0)
        return;
    if (p->f46 != 0) {
        p->f46--;
        return;
    }
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(u32 *)&_pNetState), str_0203B48C, 0, 0x2d3);
}
