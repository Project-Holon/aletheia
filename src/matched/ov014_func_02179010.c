/*
 * function: WHi_MeasureChannel
 * address:  0x02179010
 * packet:   pkt_ov014_02179010
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WM_MeasureChannel            0x02090E50  arm
*/

extern void WM_MeasureChannel(void);

asm void WHi_MeasureChannel(void)
{
	PUSH {R3, LR}
	ADD R3, R1, #0
	MOV R1, #0x1E
	STR R1, [SP, #0]
	MOV R1, #3
	MOV R2, #0x11
	BL WM_MeasureChannel
	POP {R3, PC}
}

