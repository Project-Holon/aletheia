/*
 * function: sakeGetFileIdFromHeaders
 * address:  0x021B33E0
 * packet:   pkt_ov013_021B33E0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuCopyFast              0x02082B0C  arm
*/

extern void MIi_CpuCopyFast(void);

asm void sakeGetFileIdFromHeaders(void)
{
	mov r2, r1
	ldr r1, =0x021B4C8C
	ldr ip, =MIi_CpuCopyFast
	bx ip
}

