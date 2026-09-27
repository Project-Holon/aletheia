/*
 * function: CaseInsensitiveCompare
 * address:  0x0219DF40
 * packet:   pkt_ov009_0219DF40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0209ABF8                0x0209ABF8  arm
*/

extern void func_0209ABF8(void);

asm void CaseInsensitiveCompare(void)
{
	ldr r0, [r0]
	ldr r1, [r1]
	ldr ip, =func_0209ABF8
	bx ip
}

