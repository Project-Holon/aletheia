/*
 * function: func_02004FD4
 * address: 0x02004FD4
 * packet: pkt_arm9_02004FD4
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/arm9/unit_02004FD4.c and filed here.
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
