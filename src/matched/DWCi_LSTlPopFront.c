/*
 * function: DWCi_LSTlPopFront
 * address:  0x02047250
 * packet:   pkt_02047250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E964 0x0206E964 arm
 */

extern void func_0206E964(void);
asm void DWCi_LSTlPopFront(void)
{
    ldr r0, [r0, #4]
    ldr ip, =func_0206E964
    bx ip
}
