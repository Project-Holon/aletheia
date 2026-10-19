/*
 * function: OS_InitIrqTable
 * address:  0x0208475C
 * packet:   pkt_0208475C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_interrupt.o OS_InitIrqTable (zeroes OSi_IrqThreadQueue).
 *
 * symbols:
 *   g_02FE00A0  0x02FE00A0  data  a4
 */

#include "../include/G_OSThreadQueue.h"

extern struct OSThreadQueue g_02FE00A0;

void OS_InitIrqTable(void)
{
    ((int *)&g_02FE00A0)[1] = 0;
    ((int *)&g_02FE00A0)[0] = 0;
}
