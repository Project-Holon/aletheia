/*
 * function: BTLV_INPUT_ClearSlotEvents
 * address:  0x0220680C
 * packet:   pkt_ov094_0220680C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_GetGauge  0x021F86B4  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_GAUGE_TakeSlotEvent  0x02207D78  thumb  ov094
 *   BTLV_MCSS_TakeSpriteRefreshedFlag  0x022005C4  thumb  ov094
 */
#include "../include/Obj10159.h"

extern int BTLV_EFFECT_GetGauge(void);
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_GAUGE_TakeSlotEvent(char *p, int i);
extern int BTLV_MCSS_TakeSpriteRefreshedFlag(void *w, int key);

void BTLV_INPUT_ClearSlotEvents(char *p)
{
    int a = BTLV_GAUGE_TakeSlotEvent((char *)BTLV_EFFECT_GetGauge(), ((struct Obj10159 *)p)->f278);
    int b = BTLV_MCSS_TakeSpriteRefreshedFlag((void *)BTLV_EFFECT_GetMcss(), ((struct Obj10159 *)p)->f278);
    int i;

    if ((b | a) == 1) {
        for (i = 0; i < 8; i++)
            *(char *)(p + ((struct Obj10159 *)p)->f27C * 8 + i + 0x242) = 0;
    }
}
