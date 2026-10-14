/*
 * function: POKETRADE_PROC_IsWifiMode
 * address: 0x021D8ADC
 * packet: pkt_ov119_021D8ADC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
#include "../include/Obj22703.h"
int POKETRADE_PROC_IsWifiMode(char *p)
{
    int r = 0;
    int v = ((struct Obj22703 *)p)->f118C;
    if (v == 3 || v == 9)
        r = 1;
    return r;
}
