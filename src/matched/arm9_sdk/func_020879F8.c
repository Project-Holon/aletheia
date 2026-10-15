/*
 * function: OS_SpinWaitCpuCycles
 * address:  0x020879F8
 * packet:   pkt_020879F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_SpinWaitCpuCycles    0x020879F8  arm
*/

extern void OS_SpinWaitCpuCycles(void);

asm void OS_SpinWaitCpuCycles(void)
{
    subs	r0, r0, #4
    bhs	OS_SpinWaitCpuCycles
    bx	lr
}
