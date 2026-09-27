/*
 * function: GX_DisableBankForSubBGExtPltt
 * address:  0x020809C8
 * packet:   pkt_020809C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020808BC 0x020808BC arm
 *   g_02150E62 0x02150E62 data
 */

extern void func_020808BC(void);
extern void g_02150E62(void);

asm void GX_DisableBankForSubBGExtPltt(void)
{
    ldr r2, =0x04001000
    ldr r0, =g_02150E62
    ldr	r1, [r2]
    ldr ip, =func_020808BC
    bic	r1, r1, #0x40000000
    str	r1, [r2]
    bx	ip
}
