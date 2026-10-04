/*
 * function: func_0218DE78
 * address:  0x0218DE78
 * packet:   pkt_ov021_0218DE78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../include/Obj01847.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_02082BCC(void *p, int v, int n);

void func_0218DE78(char *p)
{
    int v;

    func_02082BCC(((struct Obj01847 *)p)->f44, 0xff, ((struct Obj01847 *)p)->f2E);
    ((struct Obj01847 *)p)->f41 = 0;
    ((struct Obj01847 *)p)->f42 = ((struct Obj01847 *)p)->f43;
    ((struct Obj01847 *)p)->f43 = 0;
    ((struct Obj01847 *)p)->f4C = 0;
    if (*(volatile int *)0x02FFFC3C - ((struct Obj01847 *)p)->f50 >= 2) {
        ((struct Obj01847 *)p)->f4D = 0xff;
        ((struct Obj01847 *)p)->f48 = 0;
        return;
    }
    v = *(volatile u16 *)0x04000006;
    ((struct Obj01847 *)p)->f4D = v;
    if (v > 0xc0 || v <= 10) {
        ((struct Obj01847 *)p)->f48 = 0xf000;
        return;
    }
    ((struct Obj01847 *)p)->f48 = 0xf000 - ((v - 10) << 10);
}
