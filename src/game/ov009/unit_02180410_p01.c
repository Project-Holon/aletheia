/*
 * file:     unit_02180410_p01.c
 * unit:     yes
 * function: func_02180410, func_02180420, func_02180430
 * address:  0x02180410
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
 *   ArrayFree                    0x021841B0  arm
 *   func_020923F0                0x020923F0  arm
 */
extern void ArrayFree(void);
extern void func_020923F0(void);
asm void gsUdpMsgHandlerFree(void);
asm void gsUdpMsgHandlerCompare(void);
asm void gsUdpMsgHandlerCompare2(void);

asm void gsUdpMsgHandlerFree(void)
{
	ldr r0, [r0, #0x20]
	ldr ip, =ArrayFree
	bx ip
}

asm void gsUdpMsgHandlerCompare(void)
{
	ldr ip, =func_020923F0
	mov r2, #0x10
	bx ip
}


asm void gsUdpMsgHandlerCompare2(void)
{
	ldr ip, =func_020923F0
	add r0, r0, #0x10
	add r1, r1, #0x10
	mov r2, #0x10
	bx ip
}
