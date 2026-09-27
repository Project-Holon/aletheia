/*
 * function: CRYPTOi__BN_lshift1
 * address:  0x02164D64
 * packet:   pkt_ov009_02164D64
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WCM_InitEx                   0x02164D74  arm
*/

extern void WCM_InitEx(void);
asm void CRYPTOi__BN_lshift1(void)
{
	ldr ip, =WCM_InitEx
	mov r2, #1
	bx ip
}

