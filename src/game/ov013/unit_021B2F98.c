/*
 * file:     unit_021B2F98.c
 * function: DWCi_InitReliableQueue
 * address:  0x021B2F98
 * packet:   pkt_ov013_021B2F98
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void DWCi_InitReliableQueue(void)
{
	ldr r0, =0x021B4C24
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	bx lr
}

