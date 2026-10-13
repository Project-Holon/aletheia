/*
 * function: GFL_NET_STATE_WaitDisconnect
 * address:  0x0203BDEC
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
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_WaitDisconnect.c \
 *       --func GFL_NET_STATE_WaitDisconnect --addr 0x0203BDEC --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

struct NetState;
extern void *GFL_NET_GetSession(void);
extern void *func_0203D798(void);
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern int func_0203CEAC(int a0);

void GFL_NET_STATE_WaitDisconnect(void)
{
    u8 *p = func_0203D798();
    u8 *s = GFL_NET_GetSession();

    if ((u8)(p[0x65] + 0xFD) <= 1) {
        if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0xAC))() != 0)
            return;
        func_0203CEAC(0);
    } else {
        u8 *s2 = GFL_NET_GetSession();

        if (((*(u32 (**)(void))(*(u32 *)(s2 + 0x340) + 0x7C))() & 0xFFFE) != 0)
            return;
        func_0203CEAC(0);
    }
}
