/*
 * function: func_02086D98
 * address: 0x02086D98
 * packet: pkt_arm9_02086D98
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

/* p15 c6,c5: data protection region 5, read */
asm u32 func_02086D98(void)
{
    mrc p15, 0, r0, c6, c5, 0
    bx lr
}
