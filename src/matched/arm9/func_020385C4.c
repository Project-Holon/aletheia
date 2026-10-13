/*
 * function: GFL_NET_SYSTEM_UpdateMPParent
 * address:  0x020385C4
 * packet:   pkt_020385C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *   GFL_NET_SYSTEM_SetDebugByte  0x02037224  arm
 *   GFL_NET_SYSTEM_GetSendSize  0x02037258  arm
 *   GFL_NET_SYSTEM_SendMPParent  0x02038380  arm
 *   GFL_NET_SYSTEM_CheckAllChildRecv  0x02038524  arm
 *   GFL_NET_SYSTEM_ClearChildRecv  0x02038570  arm
 *   GFL_NET_SYSTEM_BuildSendPacket  0x02038AE0  arm
 *   GFL_NET_SYSTEM_IsConnectMember  0x02039160  arm
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A54   0x020A7A54  data
 *   g_020A7A20     0x020A7A20  data
 *   _pNetSys     0x021469D0  data
 *
 * net_system.c.  The outer per-frame entry: it dispatches on the link-state
 * byte at +0x65 of the 0x0203D798 object, in two two-wide bands written as
 * unsigned-wrapped range tests ((u8)(s - 1) <= 1 and (u8)(s - 3) <= 1), and
 * falls through to GFL_NET_SYSTEM_SendMPParent in both of the middle bands.
 * GFL_NET_SYSTEM_SetDebugByte takes the caller's __LINE__ as its second argument; the four
 * line numbers are 0x4d5, 0x4da, 0x4e1 and 0x4f4.  The assert at +0x50 is
 * the usual func_02034714(file, line, expr) triple.
 */
#include "../include/Obj03447.h"
#include "../include/G_LinkState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8   pad00[0x340];
    u32 *f340;
};

struct Oth {
    u8 pad00[0x64];
    u8 f64;
    u8 f65;
};

extern void *GFL_NET_GetSession(void);
extern void *func_0203D798(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void GFL_NET_SYSTEM_SetDebugByte(u8 v, int b);
extern u32  GFL_NET_SYSTEM_GetSendSize(void);
extern void GFL_NET_SYSTEM_SendMPParent(void);
extern int  GFL_NET_SYSTEM_CheckAllChildRecv(void);
extern void GFL_NET_SYSTEM_ClearChildRecv(void);
typedef signed int     s32;
struct Conn;
struct Hdr;
extern s32 GFL_NET_SYSTEM_BuildSendPacket(struct Hdr *h, struct Conn *c, s32 len, u8 a3);
extern int  GFL_NET_SYSTEM_IsConnectMember(u32 a);
extern const u8 str_020A7A24[];
extern const u8 str_020A7A54[];
extern u8   g_020A7A20[];
extern struct LinkState *_pNetSys;

void GFL_NET_SYSTEM_UpdateMPParent(void)
{
    struct Ctx *c = GFL_NET_GetSession();
    struct Oth *o = func_0203D798();
    u8 s = o->f65;

    if ((u8)(s + 0xff) <= 1) {
        if (GFL_NET_SYSTEM_IsConnectMember(0) == 0)
            return;
        if (o->f64 != 0)
            func_02034714((const char *)str_020A7A24, 0x4d5, (const char *)str_020A7A54);
        if (g_020A7A20[0] == 4 && *(u32 *)((u8 *)((u32 *)_pNetSys) + 0x1ac) != 0
            && GFL_NET_SYSTEM_CheckAllChildRecv() != 0)
            GFL_NET_SYSTEM_SetDebugByte(1, 0x4da);
        if (g_020A7A20[0] != 1)
            return;
        {
            u32 t = GFL_NET_SYSTEM_GetSendSize();
            if (((int (*)(u32, u32, u32, u32))c->f340[0x64 / 4])(
                    ((u32 *)((u32 *)_pNetSys))[2], t, 0, 0) == 0)
                return;
        }
        GFL_NET_SYSTEM_SetDebugByte(4, 0x4e1);
        GFL_NET_SYSTEM_ClearChildRecv();
        return;
    }
    if ((u8)(s + 0xfd) <= 1) {
        if (g_020A7A20[0] == 4) {
            u8 *g = (u8 *)((u32 *)_pNetSys);
            u32 t = GFL_NET_SYSTEM_GetSendSize();

            GFL_NET_SYSTEM_BuildSendPacket((struct Hdr *)(((struct Obj03447 *)g)->f8), (struct Conn *)(g + 0xf4), t, g[0x1d4]);
            g = (u8 *)((u32 *)_pNetSys);
            g[0x1d4] = (u8)(g[0x1d4] + 1);
            GFL_NET_SYSTEM_SetDebugByte(1, 0x4f4);
        }
        GFL_NET_SYSTEM_SendMPParent();
        return;
    }
    if (((int (*)(void))c->f340[0x70 / 4])() == 0)
        return;
    if (GFL_NET_SYSTEM_CheckAllChildRecv() == 0)
        return;
    if (g_020A7A20[0] == 4) {
        u8 *g = (u8 *)((u32 *)_pNetSys);
        u32 t = GFL_NET_SYSTEM_GetSendSize();

        GFL_NET_SYSTEM_BuildSendPacket((struct Hdr *)(((struct Obj03447 *)g)->f8), (struct Conn *)(g + 0xf4), t, g[0x1d4]);
        g = (u8 *)((u32 *)_pNetSys);
        g[0x1d4] = (u8)(g[0x1d4] + 1);
        GFL_NET_SYSTEM_SetDebugByte(1, 0x501);
    }
    GFL_NET_SYSTEM_SendMPParent();
}
