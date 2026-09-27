/*
 * function: acFree
 * address:  0x021CD570
 * packet:   pkt_ov016_021CD570
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_HEAPlFree2              0x021D647C  arm
*/

extern void DWCi_HEAPlFree2(void);

asm void acFree(void)
{
	ldr ip, =DWCi_HEAPlFree2
	mov r0, r1
	bx ip
}

