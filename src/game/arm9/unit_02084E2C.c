/*
 * file:     unit_02084E2C.c
 * function: OS_UnLockCard
 * address:  0x02084E2C
 * packet:   pkt_02084E2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084E10 0x02084E10 arm
 */

extern void func_02084E10(void);

/* hand-written in the original: ldr r1, =target; bx r1 stub, a compiled tail call uses ip */
asm void OS_UnLockCard(void)
{
    ldr r1, =func_02084E10
    bx	r1
}
