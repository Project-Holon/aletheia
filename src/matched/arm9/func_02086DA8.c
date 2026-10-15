/*
 * function: OSi_ReadProtectionRegion7
 * address: 0x02086DA8
 * packet: pkt_arm9_02086DA8
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

/* p15 c6,c7: data protection region 7, read */
asm u32 OSi_ReadProtectionRegion7(void)
{
    mrc p15, 0, r0, c6, c7, 0
    bx lr
}
