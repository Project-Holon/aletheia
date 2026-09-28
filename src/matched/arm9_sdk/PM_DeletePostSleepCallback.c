/*
 * function: PM_DeletePostSleepCallback
 * address:  0x0208C884
 * packet:   pkt_0208C884
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208C788 0x0208C788 arm
 *   g_02153004 0x02153004 data
 */

extern void func_0208C788(void);
extern void g_02153004(void);

asm void PM_DeletePostSleepCallback(void)
{
    mov	r1, r0
    ldr r0, =g_02153004
    ldr ip, =func_0208C788
    bx	ip
}
