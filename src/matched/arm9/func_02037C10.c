/*
 * function: GFL_NET_SYSTEM_Main
 * address:  0x02037C10
 * packet:   pkt_02037C10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The net tick dispatcher.  Two shapes are load-bearing: the f1EA/0x393D0
 * early exit is an out-of-line `goto bail` block placed AFTER the main body,
 * and the main path's `return 1` is reached by a `goto done` that lands on
 * the SAME `mov r0,#1; pop` the bail block falls into.  Writing either as a
 * plain `return 1` duplicates the epilogue and loses the `b #0x2037d6c`.
 *
 * symbols:
 *   lbl_021469D0   0x021469D0  data
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_WM_ICON_EasySetLevel  0x020370F4  arm
 *   GFL_NET_SYSTEM_IsError  0x020393D0  arm
 *   GFL_NET_SYSTEM_SendWireless  0x02037F48  arm
 *   GFL_NET_SYSTEM_SendWifi  0x0203802C  arm
 *   GFL_NET_SYSTEM_SendIrc  0x02038298  arm
 *   GFL_NET_SYSTEM_SendMP  0x02038340  arm
 *   GFL_NET_SYSTEM_ProcessParentRecv  0x02039050  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_SYSTEM_IsConnectMember  0x02039160  arm
 *   GFL_NET_SYSTEM_UpdateMPParent  0x020385C4  arm
 *   GFL_NET_SYSTEM_ProcessChildRecv  0x020390BC  arm
 *   GFL_NET_COMMAND_Main  0x0203ACAC  arm
 *   GFL_NET_SYSTEM_FreeWorkIfAuto  0x02037BA4  arm
 */

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

struct Net {
    u8 pad00[0x1ea];
    u8 f1EA;
};

extern struct Net *lbl_021469D0;
extern void *GFL_NET_GetSession(void);
extern void *GFL_NET_GetInitParam(void);
extern u32  GFL_NET_WM_ICON_EasySetLevel(u32 a);
extern int  GFL_NET_SYSTEM_IsError(void);
extern void GFL_NET_SYSTEM_SendWireless(void);
extern void GFL_NET_SYSTEM_SendWifi(void);
extern void GFL_NET_SYSTEM_SendIrc(void);
extern void GFL_NET_SYSTEM_SendMP(void);
extern void GFL_NET_SYSTEM_ProcessParentRecv(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int  GFL_NET_SYSTEM_IsConnectMember(u32 a);
extern void GFL_NET_SYSTEM_UpdateMPParent(void);
extern void GFL_NET_SYSTEM_ProcessChildRecv(void);
extern void GFL_NET_COMMAND_Main(void);
extern void GFL_NET_SYSTEM_FreeWorkIfAuto(void);

int GFL_NET_SYSTEM_Main(void)
{
    struct Ctx *c = GFL_NET_GetSession();
    struct Oth *o = GFL_NET_GetInitParam();

    if (lbl_021469D0 == 0) {
        if (c != 0)
            ((void (*)(u32))c->f340[0xc / 4])(0);
        return 1;
    }

    {
        u32 (*h)(void) = (u32 (*)(void))c->f340[0x84 / 4];
        if (h != 0) {
            GFL_NET_WM_ICON_EasySetLevel(h());
        }
    }

    if (lbl_021469D0->f1EA != 0)
        goto bail;
    if (GFL_NET_SYSTEM_IsError() != 0)
        goto bail;

    if (o->f64 == 0 && (o->f65 == 0 || o->f65 == 5)) {
        GFL_NET_SYSTEM_SendWireless();
    } else if ((u8)(o->f65 + 0xfd) <= 1) {
        GFL_NET_SYSTEM_SendWifi();
    } else if ((u8)(o->f65 + 0xff) <= 1) {
        GFL_NET_SYSTEM_SendIrc();
    } else {
        GFL_NET_SYSTEM_SendMP();
        GFL_NET_SYSTEM_ProcessParentRecv();
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            if (GFL_NET_SYSTEM_IsConnectMember(0) != 0 && o->f64 != 0)
                GFL_NET_SYSTEM_UpdateMPParent();
        }
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
            goto skip;
    }
    GFL_NET_SYSTEM_ProcessChildRecv();
skip:
    if (o->f65 != 1 && o->f65 != 2) {
        ((void (*)(u16))c->f340[0xc / 4])(
            *(u16 *)((u8 *)lbl_021469D0 + 0x1e4));
    }
    GFL_NET_COMMAND_Main();
    GFL_NET_SYSTEM_FreeWorkIfAuto();
    goto done;

bail:
    ((void (*)(u32))c->f340[0xc / 4])(0);
done:
    return 1;
}
