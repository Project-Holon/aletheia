/*
 * function: func_02038570
 * address:  0x02038570
 * packet:   pkt_02038380
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469D0    0x021469D0  data
 *   func_0203D680 0x0203D680  arm
 *   func_02039160 0x02039160  arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct LinkState *g_021469D0;
extern u32 func_0203D680(void);
extern u32 func_02039160(u16 a);

void func_02038570(void)
{
    int i;
    int n = func_0203D680();

    for (i = 0; i < n; i++) {
        if (func_02039160((u16)i) != 0) {
            *(u32 *)((u8 *)((u32 *)((u8 *)g_021469D0) + i) + 0x1b4) += 1;
        }
    }
}
