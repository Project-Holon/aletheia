/*
 * function: func_02177AEC
 * address:  0x02177AEC
 * packet:   pkt_ov014_02177AEC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   g_021797A4  0x021797A4  data  a4
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_021797A4;

int func_02177AEC(void)
{
    u8 *w = ((u8 *)g_021797A4);

    if (w != 0 && w[0xCEB] != 0)
        return 1;
    return 0;
}
