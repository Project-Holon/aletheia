/*
 * function: func_0203516C
 * address:  0x0203516C
 * packet:   pkt_0203516C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203515C 0x0203515C arm
 *   g_021469BC 0x021469BC data
 */

extern void func_0203515C(void);
extern void g_021469BC(void);

asm void func_0203516C(void)
{
    ldr r2, =g_021469BC
    mov	r1, r0
    ldr	r0, [r2]
    ldr ip, =func_0203515C
    bx	ip
}
