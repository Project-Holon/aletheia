/*
 * function: GFL_NET_SYSTEM_SendParentData
 * address:  0x02037E60
 * packet:   pkt_02037E60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_SYSTEM_IsConnectMember  0x02039160  arm
 *   GFL_NET_SYSTEM_SendCallback  0x02038A48  arm
 *   GFL_NET_SYSTEM_RecvChildData  0x020387A0  arm
 *   g_020A7A20     0x020A7A20  data
 *   _pNetSys     0x021469D0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Vtbl {
    u8   pad00[0x64];
    u32 (*f64)(u32, u32, u32, void *);   /* 0x64 */
    u8   pad68[0x70 - 0x68];
    u32 (*f70)(void);                    /* 0x70 */
};

struct Ctx {
    u8           pad00[0x340];
    struct Vtbl *f340;                   /* 0x340 */
};

struct State {
    u32 f0;                              /* 0x00 */
    u8  pad04[0x1b0 - 0x04];
    u32 f1b0;                            /* 0x1b0 */
};

extern void *GFL_NET_GetSession(void);
extern u32           GFL_NET_GetChildSendSize(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32           GFL_NET_SYSTEM_IsConnectMember(u32 a);
extern int GFL_NET_SYSTEM_SendCallback(int a);
typedef signed int     s32;
extern int GFL_NET_SYSTEM_RecvChildData(u32 i, u8 *p, s32 n);
extern u8            g_020A7A20[];
extern struct State *_pNetSys;

void GFL_NET_SYSTEM_SendParentData(void)
{
    struct Ctx *c = GFL_NET_GetSession();
    u32 v = GFL_NET_GetChildSendSize();
    u32 r;

    r = c->f340->f70();
    if (r == 0)
        return;
    r = GFL_NET_SYSTEM_GetCurrentAid();
    r = GFL_NET_SYSTEM_IsConnectMember(r);
    if (r == 0)
        return;
    if (g_020A7A20[1] != 0)
        return;
    if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
        r = c->f340->f64(_pNetSys->f0, v, 0, GFL_NET_SYSTEM_SendCallback);
        if (r == 0)
            return;
        g_020A7A20[1] = 2;
        _pNetSys->f1b0 = _pNetSys->f1b0 + 1;
    } else {
        g_020A7A20[1] = 2;
        GFL_NET_SYSTEM_SendCallback(1);
        GFL_NET_SYSTEM_RecvChildData(0, (u8 *)_pNetSys->f0, (u16)v);
        _pNetSys->f1b0 = _pNetSys->f1b0 + 1;
    }
}
