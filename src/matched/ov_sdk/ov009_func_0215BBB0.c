/*
 * function: func_0215BBB0
 * address:  0x0215BBB0
 * packet:   pkt_ov009_0215BBB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dacktimer (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_0208574C  0x0208574C  arm
 *   func_0215BAC0  0x0215BAC0  arm  ov009
 *   func_020857B0  0x020857B0  arm
 *   g_021A85E4  0x021A85E4  data
 */

#include "../include/G_021A85E4.h"

extern struct G_021A85E4 g_021A85E4;
extern int func_0208574C(void *thread);
extern void func_0215BAC0(void);
extern void func_020857B0(void *queue);

void func_0215BBB0(void)
{
    if (func_0208574C(((char *)&g_021A85E4)))
        return;
    do {
        func_0215BAC0();
        func_020857B0(0);
    } while (!func_0208574C(((char *)&g_021A85E4)));
}
