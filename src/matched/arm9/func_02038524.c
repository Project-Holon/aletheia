/*
 * function: func_02038524
 * address:  0x02038524
 * packet:   pkt_02038380
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469D0    0x021469D0  data
 *   func_02039160 0x02039160  arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct LinkState *g_021469D0;
extern u32 func_02039160(u16 a);

int func_02038524(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (func_02039160((u16)i) != 0 && *(int *)(((u8 *)g_021469D0) + 0x1b4 + i * 4) > 0) {
            return 0;
        }
    }
    return 1;
}
