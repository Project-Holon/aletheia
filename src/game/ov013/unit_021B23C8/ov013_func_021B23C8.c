/*
 * function: OS_InitIrqTable
 * address:  0x021B23C8
 * packet:   pkt_ov013_021B23C8
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitIrqTable (libos.TWL.HYB.a(os_interrupt.o))
 *
 * symbols:
 *   OSi_IrqThreadQueue 0x021b4be0 data
 */

extern int OSi_IrqThreadQueue;

void OS_InitIrqTable(void)
{
    ((int *)&OSi_IrqThreadQueue)[1] = 0;
    ((int *)&OSi_IrqThreadQueue)[0] = 0;
}
