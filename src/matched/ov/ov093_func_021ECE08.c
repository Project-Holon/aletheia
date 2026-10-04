/*
 * function: func_021ECE08
 * address:  0x021ECE08
 * packet:   pkt_ov093_021ECE08
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B86B8  0x021B86B8  thumb  ov093
 */
#include "../include/Obj21588.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void *func_021B86B8(void ***p);

u16 func_021ECE08(u8 *a, int b)
{
    int r;

    switch ((int)func_021B86B8(*(void *** *)&((struct Obj21588 *)a)->f134)) {
    case 0:
    default:
        r = 1;
        if (b != 1)
            r = 2;
        return r;
    case 1:
    case 2:
        if (b == 1)
            return 0xe;
        if (b == 2)
            return 0xf;
        return 0x10;
    case 3:
        if (b == 1)
            return 0x11;
        if (b == 2)
            return 0x12;
        return 0x13;
    }
}
