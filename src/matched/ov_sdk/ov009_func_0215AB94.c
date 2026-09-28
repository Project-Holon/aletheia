/*
 * function: CPS_SetUdpCallback
 * address:  0x0215AB94
 * packet:   pkt_ov009_0215AB94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void CPS_SetUdpCallback(void)
{
	ldr r1, =0x02150FEC
	ldr r1, [r1, #4]
	ldr r1, [r1, #0xa4]
	cmp r1, #0
	strne r0, [r1, #0x44]
	bx lr
}

