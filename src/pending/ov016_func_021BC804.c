/*
 * function: SendNotify
 * address:  0x021BC804
 * packet:   pkt_ov016_021BC804
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   PENDING
 *
 * symbols:
 *   ATERMi_ApConfigGetState      0x021BC7B8  arm
*/

extern void ATERMi_ApConfigGetState(void);

asm void SendNotify(void)
{
	PUSH {LR}
	SUB SP, #0xc
	ADD R0, SP, #0
	BL ATERMi_ApConfigGetState
	LDR R1, =0x021DCFD0
	ADD R0, SP, #0
	LDR R1, [R1, #0x7c]
	BLX R1
	ADD SP, #0xc
	POP {PC}
}

