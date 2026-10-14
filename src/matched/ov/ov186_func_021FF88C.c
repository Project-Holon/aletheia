/*
 * function: BR_NET_HandleNetError
 * address: 0x021FF88C
 * packet: pkt_ov186_021FF88C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   func_0200F7DC 0x0200F7DC thumb
 */
#include "../include/Obj24863.h"
extern int DWC_RAPCOMMON_HandleNetError(int, int);
extern void GFL_USE_StopAllSe(void);
extern void func_0200F7DC(void);
int BR_NET_HandleNetError(char *p)
{
    if (!p) return 0;
    switch (DWC_RAPCOMMON_HandleNetError(1, 0)) {
    case 1: GFL_USE_StopAllSe(); return 1;
    case 2: GFL_USE_StopAllSe(); ((struct Obj24863 *)p)->f5DC = 1; return 2;
    case 3: GFL_USE_StopAllSe(); func_0200F7DC(); break;
    }
    return 0;
}
