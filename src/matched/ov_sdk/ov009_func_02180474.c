/*
 * function: gsUdpRemotePeerCompare2
 * address:  0x02180474
 * packet:   pkt_ov009_02180474
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void gsUdpRemotePeerCompare2(void)
{
	ldr r2, [r0, #8]
	ldr r0, [r1, #8]
	cmp r2, r0
	movne r0, #1
	moveq r0, #0
	bx lr
}

