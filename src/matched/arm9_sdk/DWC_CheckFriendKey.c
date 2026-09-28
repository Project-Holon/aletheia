/*
 * function: DWC_CheckFriendKey
 * address:  0x02059354
 * packet:   pkt_02059354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02059374 0x02059374 arm
 */

extern void func_02059374(void);

asm void DWC_CheckFriendKey(void)
{
    mov	r3, r0
    mov	r0, r1
    mov	r1, r2
    ldr	r2, [r3, #0x24]
    ldr ip, =func_02059374
    mov	r3, #1
    bx	ip
}
