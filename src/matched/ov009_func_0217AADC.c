/*
 * function: DWC_Netcheck_GetReturnCode
 * address:  0x0217AADC
 * packet:   pkt_ov009_0217AADC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void DWC_Netcheck_GetReturnCode(void)
{
	ldr r0, =0x021ACE5C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #4]
	bx lr
}

