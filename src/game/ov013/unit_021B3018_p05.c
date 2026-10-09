/*
 * file:     unit_021B3018_p05.c
 * unit:     yes
 * function: func_021B38B0
 * address:  0x021B38B0
 * packet:   pkt_ov013_021B38B0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60CC  0x021B60CC  data  a4
 *   func_021B3924  0x021B3924  arm  ov013
 */

#include "../../matched/include/G_021B60CC.h"

extern struct G_021B60CC d_021B60CC;
extern int func_021B3924(int a, int b, int c, int *out);

int func_021B38B0(int a, int b, int c)
{
    int out[2];

    switch (func_021B3924(a, b, c, out)) {
    case 0:
        break;
    case 1:
        d_021B60CC.fn(a, out[0], out[1], d_021B60CC.arg);
        return 1;
    case 2:
        return 0;
    }
    return 1;
}
