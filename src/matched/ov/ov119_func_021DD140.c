/*
 * function: POKETRADE_PROC_TickWifiTimer
 * address: 0x021DD140
 * packet: pkt_ov119_021DD140
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsWifiMode 0x021D8ADC thumb ov119
 */
#include "../include/Obj00001.h"
extern int POKETRADE_PROC_IsWifiMode(char *p);
int POKETRADE_PROC_TickWifiTimer(char *p)
{
    if (((struct Obj00001 *)p)->f11F1) {
        if (POKETRADE_PROC_IsWifiMode(p))
            ((struct Obj00001 *)p)->f11F1 = ((struct Obj00001 *)p)->f11F1 - 1;
        else
            ((struct Obj00001 *)p)->f11F1 = 0;
    }
    return ((struct Obj00001 *)p)->f11F1 == 0;
}
