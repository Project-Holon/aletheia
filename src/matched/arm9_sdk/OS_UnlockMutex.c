/*
 * function: OS_UnlockMutex
 * address:  0x02086078
 * packet:   pkt_02086078
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OSi_UnlockMutexCore 0x02086164 arm
 */

extern void OSi_UnlockMutexCore(void);
asm void OS_UnlockMutex(void)
{
    ldr ip, =OSi_UnlockMutexCore
    mov r1, #0x10000000
    bx ip
}
