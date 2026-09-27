/*
 * function: gti2SendPong
 * address:  0x02197BA4
 * packet:   pkt_ov009_02197BA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gti2ConnectionSendData       0x02195750  arm
*/

extern void gti2ConnectionSendData(void);

asm void gti2SendPong(void)
{
	ldr ip, =gti2ConnectionSendData
	mov r3, #0x67
	strb r3, [r1, #2]
	bx ip
}

