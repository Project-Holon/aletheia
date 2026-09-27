/*
 * function: aossAlloc
 * address:  0x021C0954
 * packet:   pkt_ov016_021C0954
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

asm void aossAlloc(void)
{
	ldr ip, =DWCi_HEAPlAllocEx
	mov r1, #0x20
	bx ip
}

