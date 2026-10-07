/*
 * function: func_02039468
 * address:  0x02039468
 * packet:   pkt_02039468
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469D0   0x021469D0  data
 *   func_0203D798 0x0203D798 arm
 *   func_02036B98 0x02036B98 arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct LinkState *g_021469D0;
extern void *func_0203D798(void);
extern int func_02036B98(char *p, int v);

void func_02039468(u32 a, u32 b)
{
    u8 *s = (u8 *)func_0203D798();

    if (s[0x64] != 0 && b == 0xff) {
        func_02036B98((char *)(((u8 *)g_021469D0) + 0xf4), a);
    } else {
        func_02036B98((char *)(((u8 *)g_021469D0) + 0xcc), a);
    }
}
