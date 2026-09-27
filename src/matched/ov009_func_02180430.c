/*
 * function: gsUdpMsgHandlerCompare2
 * address:  0x02180430
 * packet:   pkt_ov009_02180430
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020923F0                0x020923F0  arm
*/

extern void func_020923F0(void);

asm void gsUdpMsgHandlerCompare2(void)
{
	ldr ip, =func_020923F0
	add r0, r0, #0x10
	add r1, r1, #0x10
	mov r2, #0x10
	bx ip
}

