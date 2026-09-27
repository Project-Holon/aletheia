/*
 * function: acAlloc
 * address:  0x021CD55C
 * packet:   pkt_ov016_021CD55C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_HEAPlAllocEx            0x021D6414  arm
*/

extern void DWCi_HEAPlAllocEx(void);

asm void acAlloc(void)
{
	ldr ip, =DWCi_HEAPlAllocEx
	mov r0, r1
	mov r1, #0x20
	bx ip
}

