/*
 * function: CPS_SocDup
 * address:  0x0215AB7C
 * packet:   pkt_ov009_0215AB7C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void CPS_SocDup(void)
{
	ldr r1, =0x02150FEC
	ldr r1, [r1, #4]
	ldr r1, [r1, #0xa4]
	str r1, [r0, #0xa4]
	bx lr
}

