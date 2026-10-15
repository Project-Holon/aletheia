/*
 * function: func_021DD27C
 * address: 0x021DD27C
 * packet: pkt_ov183_021DD27C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj24575.h"
extern void BR_UTIL_StartEffect(int obj, int one, int *args);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int func_021DD27C(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x40) <= 0x88) &
             ((unsigned int)(b - 0x10) <= 0x20);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        BR_UTIL_StartEffect(((struct Obj24575 *)p)->f10, 1, args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}
