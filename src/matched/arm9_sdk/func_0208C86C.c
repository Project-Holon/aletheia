/*
 * function: func_0208C86C
 * address:  0x0208C86C
 * packet:   pkt_0208C86C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208C788 0x0208C788 arm
 *   g_0215301C 0x0215301C data
 */

struct PMiGenCallbackInfo;
extern void func_0208C788(struct PMiGenCallbackInfo **listp, struct PMiGenCallbackInfo *info);
extern void g_0215301C(void);

asm void func_0208C86C(void)
{
    mov	r1, r0
    ldr r0, =g_0215301C
    ldr ip, =func_0208C788
    bx	ip
}
