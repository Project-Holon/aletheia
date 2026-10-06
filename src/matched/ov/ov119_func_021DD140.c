/*
 * function: func_021DD140
 * address: 0x021DD140
 * packet: pkt_ov119_021DD140
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8ADC 0x021D8ADC thumb ov119
 */
#include "../include/Obj00001.h"
extern int func_021D8ADC(char *p);
int func_021DD140(char *p)
{
    if (((struct Obj00001 *)p)->f11F1) {
        if (func_021D8ADC(p))
            ((struct Obj00001 *)p)->f11F1 = ((struct Obj00001 *)p)->f11F1 - 1;
        else
            ((struct Obj00001 *)p)->f11F1 = 0;
    }
    return ((struct Obj00001 *)p)->f11F1 == 0;
}
