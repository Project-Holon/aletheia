/*
 * function: GX_DisableBankForSubOBJExtPltt
 * address:  0x020809F0
 * packet:   pkt_020809F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020808BC 0x020808BC arm
 *   g_02150E64 0x02150E64 data
 */

typedef unsigned short u16;
extern int func_020808BC(u16 *g3bit);
extern void g_02150E64(void);

asm void GX_DisableBankForSubOBJExtPltt(void)
{
    ldr r2, =0x04001000
    ldr r0, =g_02150E64
    ldr	r1, [r2]
    ldr ip, =func_020808BC
    bic	r1, r1, #0x80000000
    str	r1, [r2]
    bx	ip
}
