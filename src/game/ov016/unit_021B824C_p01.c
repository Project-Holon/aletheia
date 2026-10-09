/*
 * file:     unit_021B824C_p01.c
 * unit:     yes
 * function: AOSS_Recvfrom
 * address:  0x021B824C
 * packet:   pkt_ov016_021B824C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SOC_RecvFrom                 0x0215F500  arm
*/

extern void SOC_RecvFrom(void);

asm void AOSS_Recvfrom(void)
{
	push {r3, r4, r5, lr}
	ldr r4, [sp, #0x14]
	ldr r5, [r4]
	ldr r4, [sp, #0x10]
	strb r5, [r4]
	str r4, [sp]
	bl SOC_RecvFrom
	pop {r3, r4, r5, pc}
}

