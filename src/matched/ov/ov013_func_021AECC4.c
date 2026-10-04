/*
 * function: func_021AECC4
 * address:  0x021AECC4
 * packet:   pkt_ov013_021AECC4
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B2180  0x021B2180  arm  ov013
 *   func_021B0614  0x021B0614  arm  ov013
 *   d_021B3C80     0x021B3C80  data  ov013
 */
#include "../include/Obj19303.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *d_021B3C80;

extern int func_021B2180(int a, int b);
extern int func_021B0614(void *p);

int func_021AECC4(void)
{
    u8 *p = *(u8 **)(d_021B3C80 + 0x1A1C);
    int r;

    if (p != 0 && ((struct Obj19303 *)p)->fC == 4) {
        r = 0;
        if (func_021B2180((int)p, 0) != 0) {
            return r;
        }
        if (func_021B0614(*(void **)(d_021B3C80 + 0x1A1C)) != 0) {
            r = 1;
        }
        return r;
    }
    return 0;
}
