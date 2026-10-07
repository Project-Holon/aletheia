/*
 * unit:     no
 * function: func_0203A53C
 * address:  0x0203A53C
 * packet:   pkt_02039CD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469D8      0x021469D8  data
 */

#include "../include/G_Entry.h"

extern void func_02082BCC(int a, int b, int c);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern struct Entry *g_021469D8;
void func_0203A53C(void)
{
    if (((int *)g_021469D8) == 0)
        return;
    func_02082BCC((int)((int *)g_021469D8), 0, 0x22c);
    func_020307B0(((int *)g_021469D8));
    g_021469D8 = 0;
}
