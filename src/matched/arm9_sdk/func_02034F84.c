/*
 * function: func_02034F84
 * address:  0x02034F84
 * packet:   pkt_02034F84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034F74 0x02034F74 arm
 */

extern void func_02034F74(void);

asm void func_02034F84(void)
{
    ldr r2, =0x021469BC
    mov r1, r0
    ldr r0, [r2]
    ldr ip, =func_02034F74
    bx ip
}
