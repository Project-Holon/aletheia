/*
 * function: OS_DisableProtectionUnit
 * address:  0x02086D04
 * packet:   pkt_02086D04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_DisableProtectionUnit (os_protectionunit.o)
 * asm:      needs mrc/mcr on cp15 c1 (no C spelling); the object agrees: no
 *           DW_TAG_variable and one strictly increasing line per instruction.
 */

asm void OS_DisableProtectionUnit(void)
{
    mrc     p15, 0, r0, c1, c0, 0
    bic     r0, r0, #1
    mcr     p15, 0, r0, c1, c0, 0
    bx      lr
}
