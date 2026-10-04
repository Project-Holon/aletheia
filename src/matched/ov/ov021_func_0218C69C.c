/*
 * function: func_0218C69C
 * address:  0x0218C69C
 * packet:   pkt_ov021_0218C69C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C530  0x0218C530  thumb  ov021
 *   func_0218C3B0  0x0218C3B0  thumb  ov021
 */
#include "../include/Obj12572.h"

unsigned char func_0218C530(int b);
void func_0218C3B0(void *p, int i, int c);

void func_0218C69C(unsigned char *p, int b, int i, int c)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= ((struct Obj12572 *)p)->f1AC)
        v = 0;
    func_0218C3B0(*(unsigned char * *)&((struct Obj12572 *)p)->f1D8 + v * 0x18, i, c);
}
