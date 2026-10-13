/*
 * function: GFL_NET_SYSTEM_SendMPParent
 * address:  0x02038380
 * packet:   pkt_02038380
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_SYSTEM_SetDebugByte  0x02037224  arm
 *   GFL_NET_SYSTEM_GetSendSize  0x02037258  arm
 *   GFL_NET_SYSTEM_ClearChildRecv  0x02038570  arm
 *   GFL_NET_SYSTEM_RecvParentData  0x02038924  arm
 *   GFL_NET_SYSTEM_SendEndCallback  0x02038A90  arm
 *   g_020A7A20     0x020A7A20  data
 *   _pNetSys     0x021469D0  data
 *
 * net_system.c.  The per-frame step of the session state machine, driven by
 * the state byte at 0x020A7A20.  GFL_NET_SYSTEM_SetDebugByte sets that byte and takes the
 * caller's __LINE__ as its second argument; the four line numbers here are
 * 0x46a, 0x46e, 0x475 and 0x48d, and the front end materialises 0x46a once
 * and derives 0x46e from it with `add r1, r4, #4`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 * 0x48d is spelled as `0x490 - 3` because the `3` is already live in r0 as
 * the state argument of the same call.
 */

#include "../include/G_LinkState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth {
    u8 pad00[0x65];
    u8 f65;
};

extern void *GFL_NET_GetSession(void);
extern struct Oth *GFL_NET_GetInitParam(void);
extern u32  GFL_NET_GetMaxConnectNum(void);
extern u32  GFL_NET_GetChildSendSize(void);
extern int  GFL_NET_SYSTEM_GetConnectNum(void);
extern void GFL_NET_SYSTEM_SetDebugByte(u8 v, int b);
extern u32  GFL_NET_SYSTEM_GetSendSize(void);
extern void GFL_NET_SYSTEM_ClearChildRecv(void);
extern void GFL_NET_SYSTEM_RecvParentData(u32 a, u32 b, u16 c);
extern int GFL_NET_SYSTEM_SendEndCallback(u32 a);
extern u8   g_020A7A20[];
extern struct LinkState *_pNetSys;

void GFL_NET_SYSTEM_SendMPParent(void)
{
    struct Ctx *c = GFL_NET_GetSession();

    GFL_NET_GetMaxConnectNum();
    if (g_020A7A20[0] == 1) {
        if (GFL_NET_SYSTEM_GetConnectNum() > 1) {
            GFL_NET_SYSTEM_SetDebugByte(2, 0x46a);
            if (((int (*)(void))c->f340[0x70 / 4])() != 0) {
                u32 t = GFL_NET_SYSTEM_GetSendSize();
                if (((int (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                        ((u32 *)_pNetSys)[2], t, 0, (u32)GFL_NET_SYSTEM_SendEndCallback) != 0)
                    goto tail;
                GFL_NET_SYSTEM_SetDebugByte(1, 0x46a + 4);
                goto tail;
            }
            if (GFL_NET_GetInitParam()->f65 != 3 && GFL_NET_GetInitParam()->f65 != 4)
                goto tail;
            if (((int (*)(void))c->f340[0xa0 / 4])() == 0) {
                GFL_NET_SYSTEM_SetDebugByte(1, 0x475);
                goto tail;
            }
            if (*(u8 *)(((u32 *)_pNetSys)[2] + 2) == 0)
                return;
            {
                u32 t = GFL_NET_GetChildSendSize();
                ((void (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                    ((u32 *)_pNetSys)[2], t, 0x64, 0);
            }
        }
    }
tail:
    if (g_020A7A20[0] == 2) {
        GFL_NET_SYSTEM_ClearChildRecv();
        GFL_NET_SYSTEM_RecvParentData(0, (u32)((u32 *)_pNetSys)[2], (u16)GFL_NET_SYSTEM_GetSendSize());
        GFL_NET_SYSTEM_SetDebugByte(3, 0x490 - 3);
    }
    if (((int (*)(void))c->f340[0x70 / 4])() == 0)
        goto last;
    if (GFL_NET_GetInitParam()->f65 == 3)
        goto last;
    if (GFL_NET_GetInitParam()->f65 != 4)
        return;
last:
    GFL_NET_SYSTEM_SetDebugByte(4, 0x492);
}
