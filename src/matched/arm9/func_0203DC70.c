/*
 * function: GFL_NET_IRC_WIRELESS_Main
 * address:  0x0203DC70
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  The wireless link state machine: a 19-state switch on
 * +0x109 of the context at 0x021469F0 (GFL_NET_IRC_WIRELESS_SetState is the setter), run
 * once per frame.  Every concrete byte reproduces (1968/1968, 78 of 80
 * relocation sites resolved).  The only lever beyond the straight reading
 * was state 11's loop counter: `i = 0;` is assigned BEFORE the
 * func_02087C6C(mac) call (the image's `mov sb, r8` precedes the `bl`).
 *
 * blocker:  the two remaining sites, GFL_NET_ConnectMacAddressParent (+0x484) and
 *           func_0203D000 (+0x4F0), are ARM tail-call wrappers (both now
 *           EXACT in pkt_0203DC70) that layout/symbols_sdk.txt/.json list as
 *           DWC_IsSendableReliable and FATFS_FormatDrive with a THUMB flag, a
 *           false libmatch signature hit.  With `arm` on those two lines
 *           match.py refuses the file (ISA conflict); with `thumb` (below)
 *           the matched class cannot attest them.  Integrator: drop the two
 *           rows, switch both symbols lines to `arm`, re-verify: EXACT.
 * symbols:
 *   gNetIrcWirelessLink     0x021469F0  data
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02039338  0x02039338  arm
 *   GFL_NET_HANDLE_GetNegotiationNum  0x020399EC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CF10  0x0203CF10  arm
 *   GFL_NET_GetScanResultMac  0x0203CF3C  arm
 *   GFL_NET_ConnectMacAddressParent  0x0203CFF0  arm
 *   func_0203D000  0x0203D000  arm
 *   func_0203D010  0x0203D010  arm
 *   func_0203D01C  0x0203D01C  arm
 *   GFL_NET_StartChangeoverChild  0x0203D0DC  arm
 *   GFL_NET_SetLinkTimeout  0x0203D17C  arm
 *   func_0203D210  0x0203D210  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_IRC_WIRELESS_DestroyIfIdle  0x0203DA20  arm
 *   GFL_NET_IRC_WIRELESS_OnSyncReady  0x0203DC04  arm
 *   GFL_NET_IRC_WIRELESS_OnConnectEnd  0x0203DC4C  arm
 *   GFL_NET_IRC_WIRELESS_SetState  0x0203DC68  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02087C6C  0x02087C6C  arm
 */

#include "../include/G_Ctx.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct VTbl {
    u8    pad_00[0xC8];
    void (*fc8)(u32 arg);
};

struct Sys {
    u8           pad_00[0x340];
    struct VTbl *f340;
};

extern struct Ctx *gNetIrcWirelessLink;
typedef signed int     s32;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern u16 func_02039338(void);
extern int  GFL_NET_HANDLE_GetNegotiationNum(void);
extern int  func_02039ACC(void);
struct Req;
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern int  func_0203CD98(void);
extern int func_0203CEAC(int a0);
extern u32 func_0203CF10(u32 a);
extern void *GFL_NET_GetScanResultMac(u32 a);
extern void GFL_NET_ConnectMacAddressParent(void *p);
extern void func_0203D000(void *p);
extern void func_0203D010(void);
extern void func_0203D01C(void);
extern int GFL_NET_StartChangeoverChild(int a0);
extern void GFL_NET_SetLinkTimeout(u32 a);
extern u32 func_0203D210(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern struct Sys *GFL_NET_GetSession(void);
extern void GFL_NET_IRC_WIRELESS_DestroyIfIdle(void);
extern void GFL_NET_IRC_WIRELESS_OnSyncReady(void);
extern void GFL_NET_IRC_WIRELESS_OnConnectEnd(void);
extern void GFL_NET_IRC_WIRELESS_SetState(struct Ctx *p, int state);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_02087C6C(u8 *mac);

void GFL_NET_IRC_WIRELESS_Main(void)
{
    struct Ctx *p = gNetIrcWirelessLink;

    if (p == 0)
        return;

    switch (p->f109) {
    case 0:
        if (p->f102 != 1)
            return;
        p->f101 = 1;
        func_02039C68((struct Link *)func_020399A8(), 3, 0);
        GFL_NET_IRC_WIRELESS_SetState(p, 1);
        break;
    case 1:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0) == 0)
            return;
        GFL_NET_IRC_WIRELESS_SetState(p, 2);
        break;
    case 2:
        if (func_02039338() == 0) {
            if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
                return;
            GFL_NET_IRC_WIRELESS_SetState(p, 3);
            p->f100 = 0xC8;
        } else {
            if (func_0203D3A8(func_020399A8(), 0x10, 0, 0) == 0)
                return;
            GFL_NET_IRC_WIRELESS_SetState(p, 3);
        }
        break;
    case 3:
        p->f100--;
        if (func_0203D210()) {
            if (gNetIrcWirelessLink->f8c != 0)
                gNetIrcWirelessLink->f8c(gNetIrcWirelessLink->arg);
            if (p->f10a != 0 && p->base_f60 == 4 && p->f105 == 0) {
                GFL_NET_IRC_WIRELESS_SetState(p, 0xE);
                p->f108++;
            } else if (p->f105 == 0 && p->base_f60 == 4) {
                p->f108++;
                func_0203CEAC(0);
                p->f88(p->arg, 1);
                GFL_NET_IRC_WIRELESS_SetState(p, 4);
            } else {
                p->f88(p->arg, 0);
                GFL_NET_IRC_WIRELESS_SetState(p, 9);
            }
        }
        if (p->f100 == 0)
            func_0203CEAC(0);
        break;
    case 4:
        if (func_0203CD98() != 0)
            return;
        p->base_f65 = 3;
        p->base_fn_2c = (void *)GFL_NET_IRC_WIRELESS_OnConnectEnd;
        if (p->f10b != 0)
            p->f67 = p->f10b;
        p->f102 = 0;
        p->f103 = 0;
        func_0203CBAC((struct Req *)p, 0, p->arg);
        GFL_NET_IRC_WIRELESS_SetState(p, 5);
        break;
    case 5:
        if (func_0203CD98() != 1)
            return;
        GFL_NET_GetSession()->f340->fc8(gNetIrcWirelessLink->f74);
        GFL_NET_StartChangeoverChild((int)((void *)GFL_NET_IRC_WIRELESS_OnSyncReady));
        GFL_NET_IRC_WIRELESS_SetState(p, 6);
        break;
    case 6:
        if (p->f102 != 1)
            return;
        p->f101 = 1;
        if (func_0203D3A8(func_020399A8(), 9, 0x24, (u32)((void *)gNetIrcWirelessLink->f90)) == 0)
            return;
        GFL_NET_IRC_WIRELESS_SetState(p, 7);
        break;
    case 7:
        if (p->f102 != 1)
            return;
        if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
            return;
        GFL_NET_SetLinkTimeout(0xC8);
        GFL_NET_IRC_WIRELESS_SetState(p, 8);
        break;
    case 8:
        if (func_0203D210() == 0)
            return;
        if (gNetIrcWirelessLink->f8c != 0)
            gNetIrcWirelessLink->f8c(gNetIrcWirelessLink->arg);
        GFL_NET_IRC_WIRELESS_SetState(p, 9);
        break;
    case 9:
        if (func_0203D210() == 0)
            return;
        if (p->f10b != 0) {
            p->f6e = 0;
            p->f67 = p->f10b;
        }
        p->base_f65 = 0;
        p->base_fn_2c = p->fn_2c;
        p->base_f64 = p->f104;
        func_0203CBAC((struct Req *)p, 0, p->arg);
        gNetIrcWirelessLink->f101 = 0;
        GFL_NET_IRC_WIRELESS_SetState(p, 0xA);
        break;
    case 10:
        if (func_0203CD98() != 1)
            return;
        if (p->f105 == 0) {
            func_0203D01C();
            GFL_NET_IRC_WIRELESS_SetState(p, 0xC);
        } else if (p->base_f60 == 4) {
            func_0203D010();
            GFL_NET_IRC_WIRELESS_SetState(p, 0xB);
        } else {
            GFL_NET_ConnectMacAddressParent(p->f94);
            GFL_NET_IRC_WIRELESS_SetState(p, 0xC);
        }
        break;
    case 11: {
        u8 mac[6];
        int i;
        int j;
        u8 *q;

        i = 0;
        func_02087C6C(mac);
        for (;; i++) {
            q = (u8 *)func_0203CF10((int)i);
            if (q == 0)
                return;
            for (j = 0; j < 4; j++) {
                if (func_0203EFC8(mac, q + 4 + j * 8, 6) == 0) {
                    func_0203D000(GFL_NET_GetScanResultMac((u32)i));
                    GFL_NET_IRC_WIRELESS_SetState(p, 0xC);
                    break;
                }
            }
        }
    }
    case 12:
        if (p->f105 == 0) {
            if (GFL_NET_HANDLE_GetNegotiationNum() == 0)
                return;
            if (func_02039ACC() != 1)
                return;
            GFL_NET_IRC_WIRELESS_SetState(p, 0xD);
        } else {
            if (func_02039ACC() != 1)
                return;
            GFL_NET_IRC_WIRELESS_SetState(p, 0xD);
        }
        break;
    case 13:
        if (p->f105 != 0) {
            if (p->f84 != 0)
                p->f84(p->arg);
            GFL_NET_IRC_WIRELESS_DestroyIfIdle();
        } else {
            if (GFL_NET_HANDLE_GetNegotiationNum() < p->f107)
                return;
            if (p->f84 != 0)
                p->f84(p->arg);
            GFL_NET_IRC_WIRELESS_DestroyIfIdle();
        }
        break;
    case 14:
        if (func_0203CD98() != 0)
            return;
        p->base_f65 = 3;
        p->base_fn_2c = (void *)GFL_NET_IRC_WIRELESS_OnConnectEnd;
        p->f102 = 0;
        p->f103 = 0;
        func_0203CBAC((struct Req *)p, 0, p->arg);
        GFL_NET_IRC_WIRELESS_SetState(p, 0xF);
        break;
    case 15:
        if (func_0203CD98() != 1)
            return;
        GFL_NET_GetSession()->f340->fc8(gNetIrcWirelessLink->f74);
        GFL_NET_StartChangeoverChild((int)((void *)GFL_NET_IRC_WIRELESS_OnSyncReady));
        GFL_NET_IRC_WIRELESS_SetState(p, 0x10);
        break;
    case 16:
        if (p->f102 != 1)
            return;
        func_02039C68((struct Link *)func_020399A8(), 3, 0);
        gNetIrcWirelessLink->f101 = 1;
        GFL_NET_IRC_WIRELESS_SetState(p, 0x11);
        break;
    case 17:
        if (func_02039CB4((struct Link *)func_020399A8(), 3, 0) == 0)
            return;
        if (func_0203D3A8(func_020399A8(), 1, 0, 0) == 0)
            return;
        GFL_NET_IRC_WIRELESS_SetState(p, 0x12);
        p->f100 = 0xC8;
        break;
    case 18:
        p->f100--;
        if (func_0203D210() == 0 && p->f100 != 0)
            return;
        if (gNetIrcWirelessLink->f8c != 0)
            gNetIrcWirelessLink->f8c(gNetIrcWirelessLink->arg);
        if (p->f10a != 0 && p->f108 < 3) {
            p->f108++;
            if (p->f108 >= 3)
                GFL_NET_IRC_WIRELESS_SetState(p, 9);
            else
                GFL_NET_IRC_WIRELESS_SetState(p, 0xE);
        } else {
            GFL_NET_IRC_WIRELESS_SetState(p, 9);
        }
        break;
    }
}
