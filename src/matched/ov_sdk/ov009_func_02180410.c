/*
 * function: gsUdpMsgHandlerFree
 * address:  0x02180410
 * packet:   pkt_ov009_02180410
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ArrayFree                    0x021841B0  arm
*/

extern void ArrayFree(void);
asm void gsUdpMsgHandlerFree(void)
{
	ldr r0, [r0, #0x20]
	ldr ip, =ArrayFree
	bx ip
}

