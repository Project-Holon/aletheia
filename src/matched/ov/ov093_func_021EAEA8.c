/*
 * function: BTLV_CORE_ShowCounterValue
 * address:  0x021EAEA8
 * packet:   pkt_ov093_021EAEA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCD_ShowCounterScreen  0x0689B780  thumb  ov095
 */
#include "../include/Obj07848.h"
typedef unsigned char u8;
extern void BTLV_SCD_ShowCounterScreen(void *, void *);
void BTLV_CORE_ShowCounterValue(u8 *p, int v)
{
    ((struct Obj07848 *)p)->f160 = v;
    ((struct Obj07848 *)p)->f164 = v;
    ((struct Obj07848 *)p)->f16C = 3;
    BTLV_SCD_ShowCounterScreen(((struct Obj07848 *)p)->f180, p + 0x160);
}
