/*
 * function: func_0218C674
 * address:  0x0218C674
 * packet:   pkt_ov021_0218C674
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C530  0x0218C530  thumb  ov021
 *   func_0218B924  0x0218B924  thumb  ov021
 *   func_0218BCB0  0x0218BCB0  thumb  ov021
 */
#include "../include/Obj19537.h"

unsigned char func_0218C530(int b);
int func_0218B924(unsigned char *p, int v);
unsigned char func_0218BCB0(unsigned short *p);

int func_0218C674(unsigned char *p, int b)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= ((struct Obj19537 *)p)->f1AC)
        v = 0;
    return func_0218BCB0((short unsigned int *)func_0218B924(p, v));
}
