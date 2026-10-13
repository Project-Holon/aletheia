/*
 * function: GFL_NET_DEVWIFI_Setup
 * address:  0x02155168
 * packet:   pkt_ov009_02155168
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   DWC_RAPCOMMON_CreateHeap  0x02157048  thumb  ov009
 *   func_02030734  0x02030734  arm
 *   _pSetupParam     0x021A8260  data  ov009  a4
 *   d_021A1C4C     0x021A1C4C  data  ov009  a1
 */
#include "../include/Obj12254.h"

extern int *_pSetupParam;
extern char d_021A1C4C[];
void *GFL_NET_GetInitParam(void);
typedef unsigned short u16;
typedef unsigned int   u32;
void DWC_RAPCOMMON_CreateHeap(u32 a, u32 b);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

int GFL_NET_DEVWIFI_Setup(int a, int b)
{
    int p;

    if (_pSetupParam != 0)
        return 0;
    p = (int)GFL_NET_GetInitParam();
    DWC_RAPCOMMON_CreateHeap(((struct Obj12254 *)p)->f58, ((struct Obj12254 *)p)->f48);
    _pSetupParam = func_02030734(a, 8, 1, d_021A1C4C, 0xba);
    *_pSetupParam = b;
    return 1;
}
