/*
 * function: gsUdpMsgHandlerCompare
 * address:  0x02180420
 * packet:   pkt_ov009_02180420
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
asm void gsUdpMsgHandlerCompare(void)
{
	ldr ip, =func_020923F0
	mov r2, #0x10
	bx ip
}

