/*
 * file:     unit_02004FD4.c
 * unit:     yes
 * function: func_02004FD4
 * address:  0x02004FD4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    crt0 helper copied to WRAM (0x01FF8000) at boot; a table sits
 *           between it and func_02004F94, so it is its own unit.  Bumps the u16
 *           at r0 until the u16 at r1 changes, then once more.
 */
asm void func_02004FD4(void)
{
    ldrh r2, [r1]
    ldrh r3, [r0]
_again:
    add r3, r3, #1
    strh r3, [r0]
    ldrh ip, [r1]
    cmp r2, ip
    beq _again
    add r3, r3, #1
    strh r3, [r0]
    bx lr
}
