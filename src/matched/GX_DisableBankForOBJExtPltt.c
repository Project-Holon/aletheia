/*
 * function: GX_DisableBankForOBJExtPltt
 * address:  0x02080940
 * packet:   pkt_02080940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020808BC 0x020808BC arm
 *   g_02150E5C 0x02150E5C data
 */

extern void func_020808BC(void);
extern void g_02150E5C(void);

asm void GX_DisableBankForOBJExtPltt(void)
{
    mov	r2, #0x4000000
    ldr	r1, [r2]
    ldr r0, =g_02150E5C
    bic	r1, r1, #0x80000000
    ldr ip, =func_020808BC
    str	r1, [r2]
    bx	ip
}
