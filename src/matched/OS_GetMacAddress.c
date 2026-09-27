/*
 * function: OS_GetMacAddress
 * address:  0x02087C6C
 * packet:   pkt_02087C6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */

extern void func_02082D44(void);

asm void OS_GetMacAddress(void)
{
    mov	r1, r0
    ldr r0, =0x02FFFCF4
    ldr ip, =func_02082D44
    mov	r2, #6
    bx	ip
}
