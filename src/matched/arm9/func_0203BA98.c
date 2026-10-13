/*
 * function: GFL_NET_STATE_StartChangeover
 * address:  0x0203BA98
 * packet:   pkt_0203BA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState      0x021469DC  data
 *   GFL_NET_SYSTEM_ConnectDevice  0x020377B8  arm
 *   GFL_NET_SYSTEM_StartBeaconScan  0x02037928  arm
 *   GFL_NET_SYSTEM_ConnectToParent  0x02037A6C  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_STATE_ExtendConnectTimer  0x0203B01C  arm
 *   GFL_NET_STATE_ChangeoverChildMain  0x0203B950  arm
 *   GFL_NET_STATE_ChangeoverChildScan  0x0203B9D4  arm
 *   GFL_NET_STATE_ChangeChangeoverMode  0x0203BC58  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 */

#include "../include/G_Sys.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern struct Sys *_pNetState;

extern void *func_0203D798(void);
extern void *GFL_NET_GetSession(void);
extern void GFL_NET_STATE_ChangeChangeoverMode(u8, u8, const void *);
extern u32  GFL_NET_SYSTEM_ConnectDevice(u8);
extern void GFL_NET_STATE_ChangeStateDebug(u32, u32, u32, u32);
extern void GFL_NET_STATE_ChangeoverChildScan(u8 *);
extern void GFL_NET_STATE_ChangeoverChildMain(u8 *p);
extern void GFL_NET_STATE_ExtendConnectTimer(void);
extern u32  GFL_NET_SYSTEM_StartBeaconScan(u32, u16);
extern void GFL_NET_SYSTEM_ConnectToParent(u32, u32, u16, u32);

void GFL_NET_STATE_StartChangeover(u16 a0, u32 a1, u8 a2)
{
    u8 *s = func_0203D798();
    u8 *p;
    u64 x, y, r;
    u32 delay = 30;

    GFL_NET_GetSession();
    GFL_NET_STATE_ChangeChangeoverMode(0, a2, 0);

    if (s[0x65] == 3 || s[0x65] == 4) {
        GFL_NET_SYSTEM_ConnectDevice(0);
        *(u32 *)(((u8 *)_pNetState) + 0x2C) = a1;
        p = ((u8 *)_pNetState);
        x = *(u64 *)(p + 0x0C);
        y = *(u64 *)(p + 0x14);
        r = y * x + *(u64 *)(p + 0x1C);
        *(u64 *)(p + 0x0C) = r;
        GFL_NET_STATE_ChangeStateDebug((u32)p, (u32)GFL_NET_STATE_ChangeoverChildScan, (u32)(((u64)(u32)(r >> 32) * delay) >> 32), delay + 0x3A8);
    } else {
        p = ((u8 *)_pNetState);
        if (p[0x53] != 0 && p[0x56] != 1) {
            GFL_NET_SYSTEM_ConnectToParent(1, (u32)(p + 0x57), 0x200, (u32)GFL_NET_STATE_ExtendConnectTimer);
        } else {
            GFL_NET_SYSTEM_StartBeaconScan(1, 0x200);
        }
        *(u32 *)(((u8 *)_pNetState) + 0x2C) = a1;
        p = ((u8 *)_pNetState);
        GFL_NET_STATE_ChangeStateDebug((u32)p, (u32)GFL_NET_STATE_ChangeoverChildMain, delay, delay + 0x3B4);
    }
}
