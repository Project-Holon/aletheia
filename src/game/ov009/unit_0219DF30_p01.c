/*
 * file:     unit_0219DF30_p01.c
 * unit:     yes
 * function: func_0219DF30, func_0219DF40
 * address:  0x0219DF30
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   StringHash                   0x0219E848  arm
 *   func_0209ABF8                0x0209ABF8  arm
 */
extern void StringHash(void);
extern void func_0209ABF8(void);
asm void KeyValHashKey(void);
asm void CaseInsensitiveCompare(void);

asm void KeyValHashKey(void)
{
	ldr r0, [r0]
	ldr ip, =StringHash
	bx ip
}


asm void CaseInsensitiveCompare(void)
{
	ldr r0, [r0]
	ldr r1, [r1]
	ldr ip, =func_0209ABF8
	bx ip
}
