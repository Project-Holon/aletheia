/*
 * function: POKETRADE_NEGO_StepWaitSelectionDelay
 * address:  0x021DE3BC
 * packet:   pkt_ov119_021DE3BC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_StepBrowseOffers  0x021DE3E8  thumb  ov119
 */
#include "../include/Obj22743.h"

typedef unsigned int   u32;
extern u32 GFL_NET_IsNetTypeWifi(void);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_StepBrowseOffers(char *p);

void POKETRADE_NEGO_StepWaitSelectionDelay(char *p)
{
    int lim;
    lim = 3;
    if (GFL_NET_IsNetTypeWifi() != 0) {
        lim = 10;
    }
    if (((struct Obj22743 *)p)->fF2C > lim) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepBrowseOffers);
    }
}
