/*
 * function: func_0216BAF4
 * address:  0x0216BAF4
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_GetGT2Connection: the connection whose aid matches, or zero.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   g_021AA8A0  0x021AA8A0  data
 *   func_02195E78  0x02195E78  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern int g_021AA8A0[];
extern int func_02195E78(const int *p);

int func_0216BAF4(int aid)
{
    int i;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0) {
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        if (g_021AA8A0[i] != 0 && aid == ((unsigned char *)func_02195E78((const int *)g_021AA8A0[i]))[1]) {
            return g_021AA8A0[i];
        }
    }
    return 0;
}
