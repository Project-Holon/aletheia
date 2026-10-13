/*
 * function: GFL_NET_STATE_ChangeoverParentConnectWait
 * address:  0x0203B52C
 * packet:   pkt_0203B52C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Wave 14: the "unresolvable" second tag site was a misread.  The pool word
 * at 0x0203B5CC (+0xA0) is 0x0203C00C (bytes 0c c0 03 02), not 0x0203B40C;
 * 0x0203C00C is the same tag GFL_NET_STATE_DeviceInitialized passes and resolves `literal`.
 * The first tag, 0x0203B4DC, resolves `matched` (src/matched/GFL_NET_STATE_ChangeoverStopParentRetry.c).
 * The callback takes func_0203D650's result in r0, which is why the
 * function pointer is loaded into r1 (docs/families/net_state.h, THE
 * CALLBACK ARITY RULE).
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   GFL_NET_SYSTEM_IsError  0x020393D0  arm
 *   GFL_NET_SYSTEM_GetChildBitmap  0x020393A8  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_HANDLE_GetNegotiationNum  0x020399EC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_0203D650  0x0203D650  arm
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_ChangeoverStopParentRetry  0x0203B4DC  arm
 *   GFL_NET_STATE_Idle  0x0203C00C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverParentConnectWait.c \
 *       --func GFL_NET_STATE_ChangeoverParentConnectWait --addr 0x0203B52C --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern struct Sys *_pNetState;
extern void GFL_NET_STATE_ChangeoverStopParentRetry(void);
extern void GFL_NET_STATE_Idle(void);

extern void *func_0203D798(void);
extern int GFL_NET_SYSTEM_IsError(void);
extern int GFL_NET_SYSTEM_GetChildBitmap(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern int func_02039ACC(void);
extern u32   func_0203D650(void);

struct Slot {
    u8  pad_00[0x2c];
    u32 f2c;
};

void GFL_NET_STATE_ChangeoverParentConnectWait(struct Slot *p)
{
    func_0203D798();
    if (GFL_NET_SYSTEM_IsError() != 0)
        return;
    if (GFL_NET_SYSTEM_GetChildBitmap() == 0) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(u32 *)&_pNetState), (void *)GFL_NET_STATE_ChangeoverStopParentRetry, 0, 0x297);
        return;
    }
    if (GFL_NET_HANDLE_GetNegotiationNum() == 0)
        return;
    if (func_02039ACC() == 0)
        return;
    if (p->f2c != 0) {
        ((void (*)(u32))p->f2c)(func_0203D650());
        p->f2c = 0;
    }
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)(*(u32 *)&_pNetState), (void *)GFL_NET_STATE_Idle, 0, 0x2a6);
}
