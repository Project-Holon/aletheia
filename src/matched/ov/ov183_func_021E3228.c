/*
 * function: func_021E3228
 * address:  0x021E3228
 * packet:   pkt_021E3228
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021FD860  0x021FD860  thumb  ov186
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */
#include "../include/Obj24697.h"

extern void func_021FD860(int obj, int one, int *args);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int func_021E3228(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x90) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);

    if (ok) {
        int args[2];

        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24697 *)p)->f34, 1, args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}
