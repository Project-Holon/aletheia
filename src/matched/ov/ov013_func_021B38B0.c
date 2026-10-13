/*
 * function: VCT_ReceiveFrame
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
 *   gVctState  0x021B60CC  data  a4
 *   VCT_ParseFrame  0x021B3924  arm  ov013
 */

#include "../include/G_021B60CC.h"

extern struct G_021B60CC gVctState;
extern int VCT_ParseFrame(int a, int b, int c, int *out);

int VCT_ReceiveFrame(int a, int b, int c)
{
    int out[2];

    switch (VCT_ParseFrame(a, b, c, out)) {
    case 0:
        break;
    case 1:
        gVctState.fn(a, out[0], out[1], gVctState.arg);
        return 1;
    case 2:
        return 0;
    }
    return 1;
}
