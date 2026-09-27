/*
 * function: _DWCi_MOV_EraseFlashData
 * address:  0x021D455C
 * packet:   pkt_ov016_021D455C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void _DWCi_MOV_EraseFlashData(void)
{
	ldr r0, =0x021DE668
	mov r1, #0xc
	ldr r0, [r0]
	strb r1, [r0, #0xa90]
	bx lr
}

