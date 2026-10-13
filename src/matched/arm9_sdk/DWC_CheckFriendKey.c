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
 *   DWC_Acc_CheckFriendKey 0x02059374 arm
 */

extern int DWC_Acc_CheckFriendKey(unsigned long long friendkey, unsigned long gamecode, int method);

asm int DWC_CheckFriendKey(void *data, unsigned long long friendKey)
{
    mov	r3, r0
    mov	r0, r1
    mov	r1, r2
    ldr	r2, [r3, #0x24]
    ldr ip, =DWC_Acc_CheckFriendKey
    mov	r3, #1
    bx	ip
}
