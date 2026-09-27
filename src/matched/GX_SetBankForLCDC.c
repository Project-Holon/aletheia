/*
 * function: GX_SetBankForLCDC
 * address:  0x0208068C
 * packet:   pkt_0208068C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02150E4C 0x02150E4C data
 *   func_0207FD34 0x0207FD34 arm
 */

extern void g_02150E4C(void);
extern void func_0207FD34(void);
asm void GX_SetBankForLCDC(void)
{
    ldr r2, =g_02150E4C
    mov r1, r0, lsl #16
    ldrh r3, [r2]
    ldr ip, =func_0207FD34
    orr r1, r3, r1, lsr #16
    strh r1, [r2]
    bx ip
}
