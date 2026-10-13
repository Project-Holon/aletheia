/*
 * function: func_0220680C
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
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   BTLV_GAUGE_TakeSlotEvent  0x02207D78  thumb  ov094
 *   func_022005C4  0x022005C4  thumb  ov094
 */
#include "../include/Obj10159.h"

extern int func_021F86B4(void);
extern int func_021F8694(void);
extern int BTLV_GAUGE_TakeSlotEvent(char *p, int i);
extern int func_022005C4(void *w, int key);

void func_0220680C(char *p)
{
    int a = BTLV_GAUGE_TakeSlotEvent((char *)func_021F86B4(), ((struct Obj10159 *)p)->f278);
    int b = func_022005C4((void *)func_021F8694(), ((struct Obj10159 *)p)->f278);
    int i;

    if ((b | a) == 1) {
        for (i = 0; i < 8; i++)
            *(char *)(p + ((struct Obj10159 *)p)->f27C * 8 + i + 0x242) = 0;
    }
}
