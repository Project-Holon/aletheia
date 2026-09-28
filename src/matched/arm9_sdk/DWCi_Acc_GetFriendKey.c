/*
 * function: DWCi_Acc_GetFriendKey
 * address:  0x020590AC
 * packet:   pkt_020590AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void DWCi_Acc_GetFriendKey(void)
{
    ldr	r1, [r0, #8]
    ldr	r0, [r0, #4]
    orr	r1, r1, #0
    orr	r0, r0, #0
    bx	lr
}
