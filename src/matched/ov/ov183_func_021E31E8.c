/*
 * function: BR_CODEIN_HitTestOptionLeft
 * address: 0x021E31E8
 * packet: pkt_ov183_021E31E8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj24696.h"
extern void BR_UTIL_StartEffect(int obj, int one, int *args);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int BR_CODEIN_HitTestOptionLeft(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        BR_UTIL_StartEffect(((struct Obj24696 *)p)->f34, 1, args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}
