/*
 * function: GFL_NET_STATE_ChangeoverChildConnected
 * address:  0x0203B868
 * packet:   pkt_0203B868
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState      0x021469DC  data
 *   GFL_NET_GetSession   0x0203D788  arm
 *   GFL_NET_GetInitParam   0x0203D798  arm
 *   GFL_NET_HANDLE_CheckNegotiation   0x02039ACC  arm
 *   GFL_NET_IRC_WIRELESS_IsActive   0x0203DA4C  arm
 *   GFL_NET_GetUserArg   0x0203D650  arm
 *   GFL_NET_STATE_ChangeStateDebug   0x0203AD80  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverChildConnected.c \
 *       --func GFL_NET_STATE_ChangeoverChildConnected --addr 0x0203B868 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct B868 {
    u8     pad_00[0x2C];
    void (*unk_2C)(u32);
};

extern struct Sys *_pNetState;

extern void *GFL_NET_GetInitParam(void);
extern u8  *GFL_NET_GetSession(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern int GFL_NET_IRC_WIRELESS_IsActive(void);
extern u32  GFL_NET_GetUserArg(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_ChangeoverChildConnected(struct B868 *p)
{
    GFL_NET_GetInitParam();

    if ((*(u32 (**)(void))(*(u32 *)(GFL_NET_GetSession() + 0x340) + 0xA8))() != 1)
        return;
    if (GFL_NET_HANDLE_CheckNegotiation() == 0)
        return;

    if (GFL_NET_IRC_WIRELESS_IsActive() == 1) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203B7F8, 0, 0x354);
        return;
    }

    if (p->unk_2C != 0) {
        p->unk_2C(GFL_NET_GetUserArg());
        p->unk_2C = 0;
    }

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C00C, 0, 0x35B);
}
