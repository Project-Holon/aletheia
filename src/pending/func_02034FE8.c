/*
 * function: func_02034FE8
 * address:  0x02034FE8
 * packet:   pkt_02034FE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034FD4 0x02034FD4 arm
 *   g_021469BC 0x021469BC data
 */

extern void func_02034FD4(void);
extern void g_021469BC(void);

asm void func_02034FE8(void)
{
    ldr r2, =g_021469BC
    mov	r1, r0
    ldr	r0, [r2]
    ldr ip, =func_02034FD4
    bx	ip
}
