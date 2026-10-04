/*
 * function: func_021ED1B0
 * address:  0x021ED1B0
 * packet:   pkt_ov093_021ED1B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj04385.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef int (*Cb)(void *, u32);

int func_021ED1B0(char *p)
{
    Cb f;

    f = *(Cb *)&((struct Obj04385 *)p)->fE0;
    if (f != 0) {
        if (f(p + 0xec, ((struct Obj04385 *)p)->fE8) != 0) {
            *(u32 *)&((struct Obj04385 *)p)->fE0 = 0;
            ((struct Obj04385 *)p)->fEC = 0;
        }
        return 0;
    }
    f = *(Cb *)&((struct Obj04385 *)p)->fE4;
    if (f != 0) {
        if (f(p + 0xec, ((struct Obj04385 *)p)->fE8) != 0) {
            *(u32 *)&((struct Obj04385 *)p)->fE4 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}
