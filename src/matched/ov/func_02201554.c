/*
 * function: WORLDTRADE_SERVER_StartDownload
 * address:  0x02201554
 * packet:   pkt_02201554
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_SetPair  0x0220251C  thumb  ov135
 *   DPW_TR_DownloadAsync  0x021C87FC  arm  ov114

 * State 0xc, slot cleared, then publish the 0xd/0xf pair.
 */
#include "../include/Obj12232.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void DPW_TR_DownloadAsync(u8 *p);
extern void WORLDTRADE_ADAPTER_SetPair(u8 *p, u16 a, u16 b);

int WORLDTRADE_SERVER_StartDownload(u8 *p)
{
    DPW_TR_DownloadAsync(p + 0xe4);
    ((struct Obj12232 *)p)->f28 = 0xc;
    ((struct Obj12232 *)p)->fF8C = 0;
    WORLDTRADE_ADAPTER_SetPair(p, 0xd, 0xf);
    return 2;
}
