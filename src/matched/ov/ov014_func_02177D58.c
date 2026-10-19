/*
 * function: NET_WHPIPE_SetBeaconGameInfo
 * address:  0x02177D58
 * packet:   pkt_ov014_02177D58
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  ov014  a4
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   WIH_GetSysState  0x02178E4C  thumb  ov014
 *   func_02178E28  0x02178E28  thumb  ov014
 *   WIH_SetBeaconGameInfo  0x021795D4  thumb  ov014
 */
#include "../include/Obj19335.h"
#include "../include/Obj19336.h"
#include "../include/Obj19337.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
void *GFL_NET_GetInitParam(void);
u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);
void DWCi_ScreenDC_FlushRange(void *p, u32 n);
int WIH_GetSysState(void);
void func_02178E28(void *p, u32 n);
void WIH_SetBeaconGameInfo(int a, int b, int c, int d);

void NET_WHPIPE_SetBeaconGameInfo(u8 *buf, u32 len)
{
    u8 *p = g_pWhPipeWork;
    u8 *st = GFL_NET_GetInitParam();
    if (p != 0 && st != 0) {
        ((struct Obj19335 *)buf)->f0 = GF_STANDARD_CalcCrc16(buf + 2, len - 2);
        DWCi_ScreenDC_FlushRange(buf, len);
        if (WIH_GetSysState() == 1) {
            func_02178E28(buf, (u16)len);
            return;
        }
        WIH_SetBeaconGameInfo((int)buf, len, ((struct Obj19336 *)st)->f50, ((struct Obj19337 *)p)->fC68);
    }
}
