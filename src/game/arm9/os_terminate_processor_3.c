/*
 * file:     os_terminate_processor_3.c
 * function: OS_Halt
 * address:  0x020882D0
 * packet:   pkt_020882D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_Halt(void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}
