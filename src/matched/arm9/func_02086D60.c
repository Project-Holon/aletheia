/*
 * function: func_02086D60
 * address: 0x02086D60
 * packet: pkt_arm9_02086D60
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/unit_02086D14.c and filed here.
 */

typedef unsigned long u32;

/* p15 c6,c6: data protection region 6, write */
asm void func_02086D60(u32 param)
{
    mcr p15, 0, r0, c6, c6, 0
    bx lr
}
