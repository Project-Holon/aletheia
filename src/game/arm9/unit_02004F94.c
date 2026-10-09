/*
 * file:     unit_02004F94.c
 * unit:     yes
 * function: func_02004F94
 * address:  0x02004F94
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    crt0 helper copied to WRAM (0x01FF8000) at boot; data words sit
 *           before and after it in the image, so it is its own unit (like the
 *           other crt0 pieces here).  Waits until the u16 at r0 equals r1.
 */
asm void func_02004F94(void)
{
_top:
    ldrh r2, [r0]
    cmp r1, r2
    bxeq lr
    mov r3, #0x10
_wait:
    subs r3, r3, #1
    bne _wait
    b _top
}
