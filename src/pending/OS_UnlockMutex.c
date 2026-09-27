/*
 * function: OS_UnlockMutex
 * address:  0x02086078
 * packet:   pkt_02086078
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT *
 * symbols:
 *   func_02086164 0x02086164 arm
 */

extern void func_02086164(void);
asm void OS_UnlockMutex(void)
{
    ldr ip, =func_02086164
    mov r1, #0x10000000
    bx ip
}
