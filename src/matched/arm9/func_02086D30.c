/*
 * function: OSi_WriteProtectionRegion0
 * address: 0x02086D30
 * packet: pkt_arm9_02086D30
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

/* p15 c6,c0: data protection region 0, write */
asm void OSi_WriteProtectionRegion0(u32 param)
{
    mcr p15, 0, r0, c6, c0, 0
    bx lr
}
