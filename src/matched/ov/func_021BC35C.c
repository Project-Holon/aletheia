/*
 * function: ZUKAN_DETAIL_COMMON_CreateContext
 * address:  0x021BC35C
 * packet:   pkt_ov208_021BC35C
 * region:   ov208
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021C8D98     0x021C8D98  data  ov208  a4
 */
#include "../include/Obj03064.h"

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern int d_021C8D98;

void ZUKAN_DETAIL_COMMON_CreateContext(int a, int b, int c, int d, int e, int f, int g, int h,
                   unsigned short i, int j)
{
    int *p = (int *)func_02030734(a, 0x24, 1, (const char *)&d_021C8D98, 0x60);

    p[0] = b;
    p[1] = c;
    p[2] = d;
    p[3] = e;
    p[4] = f;
    p[5] = g;
    p[6] = h;
    ((struct Obj03064 *)p)->f1C = i;
    p[8] = j;
}
