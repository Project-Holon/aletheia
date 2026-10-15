/*
 * function: OSi_WriteProtectionRegion3
 * address: 0x02086D48
 * packet: pkt_arm9_02086D48
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

/* p15 c6,c3: data protection region 3, write */
asm void OSi_WriteProtectionRegion3(u32 param)
{
    mcr p15, 0, r0, c6, c3, 0
    bx lr
}
