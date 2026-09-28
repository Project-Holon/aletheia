/*
 * function: SOCLi_DhcpTimeout
 * address:  0x0215CD0C
 * packet:   pkt_ov009_0215CD0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void SOCLi_DhcpTimeout(void)
{
	ldr r0, =0x021AA440
	ldr r1, [r0, #8]
	orr r1, r1, #2
	str r1, [r0, #8]
	bx lr
}

