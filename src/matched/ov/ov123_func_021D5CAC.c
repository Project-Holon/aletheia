/*
 * function: func_021D5CAC
 * address: 0x021D5CAC
 * packet: pkt_ov123_021D5CAC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5DB4 0x021C5DB4 arm ov114
 */
#include "../include/Obj06460.h"
extern int func_021C5DB4(void);
int func_021D5CAC(char *p)
{
    if (((struct Obj06460 *)p)->fD0) return 0;
    if (((struct Obj06460 *)p)->fCC) {
        if (++((struct Obj06460 *)p)->fCC>3600) {
            ((struct Obj06460 *)p)->fD0=1;
            if (!func_021C5DB4()) ((struct Obj06460 *)p)->fC8=1;
            return 0;
        }
    }
    return 1;
}
