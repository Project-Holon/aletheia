/*
 * function: func_02004F94
 * address: 0x02004F94
 * packet: pkt_arm9_02004F94
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/arm9/unit_02004F94.c and filed here.
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
