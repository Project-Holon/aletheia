/*
 * function: WCMi_CpsifSetMacAddress
 * address:  0x021665CC
 * packet:   pkt_ov009_021665CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy                   0x02082EA4  arm
*/

extern void MI_CpuCopy(void);

asm void WCMi_CpsifSetMacAddress(void)
{
	ldr r1, =0x021AA80C
	ldr ip, =MI_CpuCopy
	mov r2, #6
	bx ip
}

