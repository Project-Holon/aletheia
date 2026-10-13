/*
 * function: GFL_NET_STATE_ChangeoverStartParent
 * address:  0x0203B6EC
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
 *   GFL_NET_SYSTEM_StartParent  0x02037894  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_STATE_ChangeoverParentRestart  0x0203B688  arm
 *   GFL_NET_STATE_ChangeoverParentCallback  0x0203B6B4  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverStartParent.c \
 *       --func GFL_NET_STATE_ChangeoverStartParent --addr 0x0203B6EC --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern u8 *GFL_NET_GetSession(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern u32 GFL_NET_SYSTEM_StartParent(u32 a, u32 b, u32 c, u32 d);
extern int GFL_NET_STATE_ChangeoverParentCallback(int a0, int a1, int a2, int a3);
extern int GFL_NET_STATE_ChangeoverParentRestart(int a0, int a1, int a2, int a3);

void GFL_NET_STATE_ChangeoverStartParent(u8 *p)
{
    if ((*(u32 (**)(void))(*(u32 *)(GFL_NET_GetSession() + 0x340) + 0x78))() == 0)
        return;
    if (GFL_NET_SYSTEM_StartParent(0, 0x200, 0, (u32)GFL_NET_STATE_ChangeoverParentCallback) == 0)
        return;

    p[0x4C] = 0;
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)GFL_NET_STATE_ChangeoverParentRestart, 0x1E, 0x2FC);
}
