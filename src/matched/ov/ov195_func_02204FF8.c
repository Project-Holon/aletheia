/*
 * function: SHINKA_DEMO_StopBgm
 * address:  0x02204FF8
 * packet:   pkt_02204FF8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 */
#include "../include/Obj14527.h"

extern int GFL_USE_PopBgm(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);

void SHINKA_DEMO_StopBgm(int a, char *b)
{
    if (((struct Obj14527 *)b)->f30 == 5) {
        GFL_USE_PopBgm();
        GFL_USE_CancelChangeAndStopBgm();
        ((struct Obj14527 *)b)->f30 = 0;
    }
}