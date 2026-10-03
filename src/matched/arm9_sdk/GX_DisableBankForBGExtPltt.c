/*
 * function: GX_DisableBankForBGExtPltt
 * address:  0x0208091C
 * packet:   pkt_0208091C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020808BC 0x020808BC arm
 *   g_02150E5A 0x02150E5A data
 */

typedef unsigned short u16;
extern int func_020808BC(u16 *g3bit);
extern void g_02150E5A(void);

asm void GX_DisableBankForBGExtPltt(void)
{
    mov	r2, #0x4000000
    ldr	r1, [r2]
    ldr r0, =g_02150E5A
    bic	r1, r1, #0x40000000
    ldr ip, =func_020808BC
    str	r1, [r2]
    bx	ip
}
