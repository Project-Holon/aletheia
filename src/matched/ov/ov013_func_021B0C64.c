/*
 * function: func_021B0C64
 * address:  0x021B0C64
 * packet:   pkt_ov013_021B0C64
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021B60D8     0x021B60D8  data  a4
 *   g_021B3AD0     0x021B3AD0  data  a1
 *   g_021B3C84     0x021B3C84  data  a4
 */

#include "../include/G_021B3C84.h"
#include "../include/G_Sess.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern struct Sess g_021B60D8;
extern const u8 g_021B3AD0[5][2];
extern struct G_021B3C84 g_021B3C84;

int func_021B0C64(int x)
{
    if (x >= 5) {
        return 0;
    }
    if (g_021B60D8.f10 != 1 && (unsigned)x <= 1) {
        return 0;
    }
    g_021B3C84.fC = g_021B3AD0[x][0] * 0x44 + g_021B3AD0[x][1] + 0xC;
    g_021B3C84.f1C = x;
    g_021B3C84.f10 = 0;
    g_021B3C84.f12 = 0;
    return 1;
}
